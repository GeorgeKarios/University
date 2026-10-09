#[cfg(test)]
mod tests {
    use crate::types::{BorrowedValue, OwnedEntry};
    use crate::{AnorthosisStore, Key, Value};
    use crate::serialization::{RawHeader, serialize_unsafe, deserialize_unsafe};

    #[test]
    fn test_insert_and_lookup_string_entry() {
        let mut store = AnorthosisStore::new();
        store.insert(Key::Str("language".into()), Value::Str("Rust".into()));

        let borrowed = store.lookup(&Key::Str("language".into())).unwrap();
        match borrowed.value {
            BorrowedValue::Text(v) => assert_eq!(v, "Rust"),
            _ => panic!("Expected BorrowedValue::Text"),
        }
    }

    #[test]
    fn test_insert_and_lookup_integer_entry() {
        let mut store = AnorthosisStore::new();
        store.insert(Key::Int(42), Value::Str("Answer".into()));

        let borrowed = store.lookup(&Key::Int(42)).unwrap();
        match borrowed.value {
            BorrowedValue::Text(v) => assert_eq!(v, "Answer"),
            _ => panic!("Expected BorrowedValue::Text"),
        }
    }

    #[test]
    fn test_borrowed_to_owned_conversion() {
        let mut store = AnorthosisStore::new();
        store.insert(Key::Str("hello".into()), Value::Str("world".into()));

        let borrowed = store.lookup(&Key::Str("hello".into())).unwrap();
        let owned: OwnedEntry = borrowed.into();

        assert_eq!(owned.value, Value::Str("world".into()));
    }

    #[test]
    fn test_len_and_empty() {
        let mut store = AnorthosisStore::new();
        assert!(store.is_empty());
        store.insert(Key::Int(1), Value::Str("A".into()));
        assert_eq!(store.len(), 1);
        assert!(!store.is_empty());
    }

    #[test]
    fn test_nonexistent_key_lookup() {
        let store = AnorthosisStore::new();
        assert!(store.lookup(&Key::Str("missing".into())).is_none());
    }

    #[test]
    fn test_multiple_inserts_and_lookups() {
        let mut store = AnorthosisStore::new();
        store.insert(Key::Str("k1".into()), Value::Str("v1".into()));
        store.insert(Key::Str("k2".into()), Value::Str("v2".into()));
        store.insert(Key::Int(3), Value::Str("v3".into()));

        let b1 = store.lookup(&Key::Str("k1".into())).unwrap();
        let b2 = store.lookup(&Key::Str("k2".into())).unwrap();
        let b3 = store.lookup(&Key::Int(3)).unwrap();

        match (b1.value, b2.value, b3.value) {
            (BorrowedValue::Text(v1), BorrowedValue::Text(v2), BorrowedValue::Text(v3)) => {
                assert_eq!(v1, "v1");
                assert_eq!(v2, "v2");
                assert_eq!(v3, "v3");
            }
            _ => panic!("Unexpected value type"),
        }
    }

    // ------------ LAB 4 RAW HEADER TESTS ------------------

    #[test]
    fn test_rawheader_roundtrip() {
        use crate::serialization::*;

        let header = RawHeader {
            length: 20,
            checksum: 0xDEADBEEF,
            key_tag: 1,
            value_tag: 3,
        };

        let mut buf = Vec::new();
        unsafe { serialize_unsafe(&header, &mut buf); }

        let decoded = unsafe { deserialize_unsafe(&buf) };

        // IMPORTANT: COPY PACKED FIELDS BEFORE ASSERT
        let hlen = header.length;
        let hchk = header.checksum;
        let hkt = header.key_tag;
        let hvt = header.value_tag;

        let dlen = decoded.length;
        let dchk = decoded.checksum;
        let dkt = decoded.key_tag;
        let dvt = decoded.value_tag;

        assert_eq!(dlen, hlen);
        assert_eq!(dchk, hchk);
        assert_eq!(dkt, hkt);
        assert_eq!(dvt, hvt);
    }

    #[test]
    #[should_panic]
    fn test_checksum_mismatch() {
        let key = Key::Str("hello".into());
        let value = Value::Str("world".into());

        let mut buf = Vec::new();
        crate::serialization::serialize_entry(&key, &value, &mut buf);

        // corrupt body
        buf[20] ^= 0xFF;

        crate::serialization::deserialize_entry(&buf[..]);
    }
}
