use crate::types::{Key, Value, OwnedEntry, BorrowedEntry, BorrowedValue};
use std::{ptr, str};

#[repr(C, packed)]
pub struct RawHeader {
    pub length: u64,
    pub checksum: u32,
    pub key_tag: u8,
    pub value_tag: u8,
}

/* ============================== */
/*      LAB 3 – SAFE VERSION      */
/* ============================== */

pub fn serialize(entry: &OwnedEntry, buffer: &mut Vec<u8>) -> usize {
    let start = buffer.len();

    match (&entry.key, &entry.value) {
        (Key::Str(k), Value::Str(v)) => {
            buffer.push(0);
            let total_bytes =
                (2 * std::mem::size_of::<u64>() + k.len() + v.len()) as u64;
            buffer.extend_from_slice(&total_bytes.to_le_bytes());
            buffer.extend_from_slice(&(k.len() as u64).to_le_bytes());
            buffer.extend_from_slice(k.as_bytes());
            buffer.extend_from_slice(&(v.len() as u64).to_le_bytes());
            buffer.extend_from_slice(v.as_bytes());
        }
        (Key::Int(k), Value::Int(v)) => {
            buffer.push(1);
            buffer.extend_from_slice(&16u64.to_le_bytes());
            buffer.extend_from_slice(&k.to_le_bytes());
            buffer.extend_from_slice(&v.to_le_bytes());
        }
        (Key::Int(k), Value::Str(v)) => {
            buffer.push(2);
            let total_bytes = (8 + 8 + v.len() + 8) as u64;
            buffer.extend_from_slice(&total_bytes.to_le_bytes());
            buffer.extend_from_slice(&k.to_le_bytes());
            buffer.extend_from_slice(&(v.len() as u64).to_le_bytes());
            buffer.extend_from_slice(v.as_bytes());
        }
        (Key::Str(k), Value::Int(v)) => {
            buffer.push(3);
            let total_bytes =
                (2 * std::mem::size_of::<u64>() + k.len() + 8) as u64;
            buffer.extend_from_slice(&total_bytes.to_le_bytes());
            buffer.extend_from_slice(&(k.len() as u64).to_le_bytes());
            buffer.extend_from_slice(k.as_bytes());
            buffer.extend_from_slice(&v.to_le_bytes());
        }
        _ => panic!("Unsupported combination"),
    }

    start
}

pub fn deserialize<'a>(bytes: &'a [u8]) -> BorrowedEntry<'a> {
    let mut offset = 0;
    let tag = bytes[offset];
    offset += 1;

    match tag {
        0 => {
            let _total =
                u64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap());
            offset += 8;

            let k_len =
                u64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap())
                    as usize;
            offset += 8;

            let key_str =
                str::from_utf8(&bytes[offset..offset + k_len]).unwrap();
            offset += k_len;

            let v_len =
                u64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap())
                    as usize;
            offset += 8;

            let val_str =
                str::from_utf8(&bytes[offset..offset + v_len]).unwrap();

            BorrowedEntry {
                key: BorrowedValue::Text(key_str),
                value: BorrowedValue::Text(val_str),
            }
        }
        1 => {
            let _header =
                u64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap());
            offset += 8;
            let k =
                i64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap());
            offset += 8;
            let v =
                i64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap());

            BorrowedEntry {
                key: BorrowedValue::Int(k),
                value: BorrowedValue::Int(v),
            }
        }
        2 => {
            let _header =
                u64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap());
            offset += 8;

            let k =
                i64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap());
            offset += 8;

            let v_len =
                u64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap())
                    as usize;
            offset += 8;

            let v_str =
                str::from_utf8(&bytes[offset..offset + v_len]).unwrap();

            BorrowedEntry {
                key: BorrowedValue::Int(k),
                value: BorrowedValue::Text(v_str),
            }
        }
        3 => {
            let _header =
                u64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap());
            offset += 8;

            let k_len =
                u64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap())
                    as usize;
            offset += 8;

            let key_str =
                str::from_utf8(&bytes[offset..offset + k_len]).unwrap();
            offset += k_len;

            let v =
                i64::from_le_bytes(bytes[offset..offset + 8].try_into().unwrap());

            BorrowedEntry {
                key: BorrowedValue::Text(key_str),
                value: BorrowedValue::Int(v),
            }
        }
        _ => panic!("Unknown tag"),
    }
}

/* ================================== */
/*      LAB 4 – UNSAFE + HEADER       */
/* ================================== */

pub unsafe fn serialize_unsafe(header: &RawHeader, buffer: &mut Vec<u8>) -> usize {
    let offset = buffer.len();
    let header_size = std::mem::size_of::<RawHeader>();

    buffer.resize(offset + header_size, 0);

    ptr::copy_nonoverlapping(
        header as *const RawHeader,
        buffer.as_mut_ptr().add(offset).cast::<RawHeader>(),
        1,
    );

    offset
}

pub unsafe fn deserialize_unsafe(bytes: &[u8]) -> RawHeader {
    ptr::read_unaligned(bytes.as_ptr().cast::<RawHeader>())
}

/* =============================== */
/*      LAB 4 BODY SERIALIZER      */
/* =============================== */

fn serialize_body(key: &Key, value: &Value, buffer: &mut Vec<u8>) {
    match key {
        Key::Str(s) => {
            buffer.extend_from_slice(&(s.len() as u64).to_le_bytes());
            buffer.extend_from_slice(s.as_bytes());
        }
        Key::Int(i) => buffer.extend_from_slice(&i.to_le_bytes()),
    }

    match value {
        Value::Str(s) => {
            buffer.extend_from_slice(&(s.len() as u64).to_le_bytes());
            buffer.extend_from_slice(s.as_bytes());
        }
        Value::Int(i) => buffer.extend_from_slice(&i.to_le_bytes()),
        Value::Bool(b) => buffer.push(*b as u8),
        Value::Blob(b) => {
            buffer.extend_from_slice(&(b.len() as u64).to_le_bytes());
            buffer.extend_from_slice(b);
        }
    }
}

fn deserialize_body<'a>(
    body: &'a [u8],
    key_tag: u8,
    value_tag: u8,
) -> BorrowedEntry<'a> {
    let mut idx = 0;

    let key = match key_tag {
        0 => {
            let len = u64::from_le_bytes(body[idx..idx + 8].try_into().unwrap()) as usize;
            idx += 8;
            let s = std::str::from_utf8(&body[idx..idx + len]).unwrap();
            idx += len;
            BorrowedValue::Text(s)
        }
        1 => {
            let num = i64::from_le_bytes(body[idx..idx + 8].try_into().unwrap());
            idx += 8;
            BorrowedValue::Int(num)
        }
        _ => panic!("Unknown key tag"),
    };

    let value = match value_tag {
        0 => {
            let len = u64::from_le_bytes(body[idx..idx + 8].try_into().unwrap()) as usize;
            idx += 8;
            let s = std::str::from_utf8(&body[idx..idx + len]).unwrap();
            idx += len;
            BorrowedValue::Text(s)
        }
        1 => {
            let num = i64::from_le_bytes(body[idx..idx + 8].try_into().unwrap());
            BorrowedValue::Int(num)
        }
        2 => BorrowedValue::Bool(body[idx] != 0),
        3 => {
            let len = u64::from_le_bytes(body[idx..idx + 8].try_into().unwrap()) as usize;
            idx += 8;
            BorrowedValue::Blob(&body[idx..idx + len])
        }
        _ => panic!("Unknown value tag"),
    };

    BorrowedEntry { key, value }
}

/* ================================= */
/*        LAB 4 PUBLIC WRAPPERS      */
/* ================================= */

pub fn serialize_entry(key: &Key, value: &Value, buffer: &mut Vec<u8>) -> usize {
    let offset = buffer.len();

    let mut body = Vec::new();
    serialize_body(key, value, &mut body);

    let checksum = crc32fast::hash(&body);

    let header = RawHeader {
        length: body.len() as u64,
        checksum,
        key_tag: key.tag(),
        value_tag: value.tag(),
    };

    unsafe { serialize_unsafe(&header, buffer) };

    buffer.extend_from_slice(&body);

    offset
}

pub fn deserialize_entry(bytes: &[u8]) -> (BorrowedEntry<'_>, usize) {
    let header_size = std::mem::size_of::<RawHeader>();

    let raw = unsafe { deserialize_unsafe(&bytes[..header_size]) };

    // COPY PACKED FIELDS TO LOCALS
    let length = raw.length;
    let checksum = raw.checksum;
    let key_tag = raw.key_tag;
    let value_tag = raw.value_tag;

    let body_start = header_size;
    let body_end = header_size + length as usize;
    let body = &bytes[body_start..body_end];

    let computed = crc32fast::hash(body);
    assert!(computed == checksum, "Checksum mismatch");

    let entry = deserialize_body(body, key_tag, value_tag);

    (entry, body_end)
}
