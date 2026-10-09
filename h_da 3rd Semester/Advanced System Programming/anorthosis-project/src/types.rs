use std::fmt;

/// Represents keys used in the store.
#[derive(Hash, Eq, PartialEq, Debug, Clone)]
pub enum Key {
    Str(String),
    Int(i64),
}

impl Key {
    pub fn tag(&self) -> u8 {
        match self {
            Key::Str(_) => 0,
            Key::Int(_) => 1,
        }
    }
}

/// Represents values stored in the store.
#[derive(Debug, Clone, PartialEq)]
pub enum Value {
    Str(String),
    Int(i64),
    Bool(bool),
    Blob(Vec<u8>),
}

impl Value {
    pub fn tag(&self) -> u8 {
        match self {
            Value::Str(_)  => 0,
            Value::Int(_)  => 1,
            Value::Bool(_) => 2,
            Value::Blob(_) => 3,
        }
    }
}

/// A fully owned key-value entry. Used when inserting into the store.
#[derive(Debug, Clone, PartialEq)]
pub struct OwnedEntry {
    pub key: Key,
    pub value: Value,
}

/// A borrowed key-value entry (zero-copy view into the byte buffer).
#[derive(Debug, PartialEq)]
pub struct BorrowedEntry<'a> {
    pub key: BorrowedValue<'a>,
    pub value: BorrowedValue<'a>,
}

/// Borrowed version of supported value types.
#[derive(Debug, PartialEq)]
pub enum BorrowedValue<'a> {
    Text(&'a str),
    Int(i64),
    Bool(bool),
    Blob(&'a [u8]),
}

/// Conversion: Borrowed → Owned (copies data where necessary).
impl<'a> From<BorrowedEntry<'a>> for OwnedEntry {
    fn from(entry: BorrowedEntry<'a>) -> Self {
        OwnedEntry {
            key: match entry.key {
                BorrowedValue::Text(s) => Key::Str(s.to_string()),
                BorrowedValue::Int(i) => Key::Int(i),
                BorrowedValue::Bool(b) => Key::Str(b.to_string()),
                BorrowedValue::Blob(bytes) => Key::Str(format!("{:?}", bytes)),
            },
            value: match entry.value {
                BorrowedValue::Text(s) => Value::Str(s.to_string()),
                BorrowedValue::Int(i) => Value::Int(i),
                BorrowedValue::Bool(b) => Value::Bool(b),
                BorrowedValue::Blob(bytes) => Value::Blob(bytes.to_vec()),
            },
        }
    }
}

impl fmt::Display for Key {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Key::Str(s) => write!(f, "{s}"),
            Key::Int(i) => write!(f, "{i}"),
        }
    }
}

impl fmt::Display for Value {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Value::Str(s) => write!(f, "{s}"),
            Value::Int(i) => write!(f, "{i}"),
            Value::Bool(b) => write!(f, "{b}"),
            Value::Blob(bytes) => write!(f, "{:?}", bytes),
        }
    }
}
