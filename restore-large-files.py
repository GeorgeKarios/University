"""Restore release downloads to their original paths; verify every SHA-256 hash."""
import hashlib
import json
from pathlib import Path
from urllib.parse import quote
from urllib.request import Request, urlopen

ROOT = Path(__file__).resolve().parent

def sha256(path):
    digest = hashlib.sha256()
    with path.open('rb') as stream:
        for chunk in iter(lambda: stream.read(8 * 1024 * 1024), b''):
            digest.update(chunk)
    return digest.hexdigest()

def main():
    manifest = json.loads((ROOT / 'upload-manifest.json').read_text(encoding='utf-8'))
    for record in manifest['files']:
        if record['storage'] != 'release':
            continue
        target = (ROOT / record['path']).resolve()
        if ROOT not in target.parents:
            raise ValueError('Unsafe destination in manifest')
        if target.exists():
            if sha256(target) == record['sha256']:
                print('Already present:', record['path'])
                continue
            raise FileExistsError('Existing file differs; move it aside first: ' + str(target))
        target.parent.mkdir(parents=True, exist_ok=True)
        temporary = target.with_name(target.name + '.download')
        if temporary.exists():
            raise FileExistsError('Previous download exists; move it aside first: ' + str(temporary))
        print('Downloading:', record['path'])
        with temporary.open('xb') as output:
            for asset in record['assets']:
                url = 'https://github.com/' + manifest['repository'] + '/releases/download/' + quote(manifest['release_tag']) + '/' + quote(asset['name'])
                digest = hashlib.sha256()
                count = 0
                with urlopen(Request(url, headers={'User-Agent': 'University-file-restore'})) as response:
                    while True:
                        chunk = response.read(8 * 1024 * 1024)
                        if not chunk:
                            break
                        output.write(chunk)
                        digest.update(chunk)
                        count += len(chunk)
                if count != asset['size'] or digest.hexdigest() != asset['sha256']:
                    raise RuntimeError('Release asset verification failed: ' + asset['name'])
        if temporary.stat().st_size != record['size'] or sha256(temporary) != record['sha256']:
            raise RuntimeError('Restored file verification failed: ' + record['path'])
        temporary.rename(target)
        print('Verified:', record['path'])

if __name__ == '__main__':
    main()
