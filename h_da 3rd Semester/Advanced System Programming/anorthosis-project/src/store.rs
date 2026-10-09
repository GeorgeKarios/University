use std::collections::HashMap;

use crate::serialization::{serialize_entry, deserialize_entry};
use crate::types::{BorrowedEntry, Key, Value};

/// The main structure representing the key-value store.
pub struct AnorthosisStore {
    data: Vec<u8>,              // raw byte storage
    index: HashMap<Key, usize>, // key → offset in `data`
}

impl AnorthosisStore {
    pub fn new() -> Self {
        Self {
            data: Vec::new(),
            index: HashMap::new(),
        }
    }

    /// Insert a new entry by serializing it into the byte buffer.
    pub fn insert(&mut self, key: Key, value: Value) {
        let offset = serialize_entry(&key, &value, &mut self.data);
        self.index.insert(key, offset);
    }

    /// Look up a key and return a borrowed view of the data without copying.
    pub fn lookup(&self, key: &Key) -> Option<BorrowedEntry<'_>> {
        if let Some(&offset) = self.index.get(key) {
            let (entry, _) = deserialize_entry(&self.data[offset..]);
            Some(entry)
        } else {
            None
        }
    }

    pub fn len(&self) -> usize {
        self.index.len()
    }

    pub fn is_empty(&self) -> bool {
        self.index.is_empty()
    }
}
