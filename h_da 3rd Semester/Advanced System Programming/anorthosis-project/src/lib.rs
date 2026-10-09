//! AnorthosisStore — A byte-level key-value store

pub mod serialization;
pub mod store;
pub mod types;

pub use store::AnorthosisStore;
pub use types::{BorrowedEntry, Key, OwnedEntry, Value};

#[cfg(test)]
mod tests;
