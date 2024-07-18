# abseil 源码阅读

### [Containers](https://abseil.io/docs/cpp/guides/container)

Abseil provides a number of containers as alternatives to STL containers. 
These containers generally adhere to the properties of STL containers, 
though there are often some associated API differences and/or implementation 
details which differ from the standard library.

The Abseil containers are designed to be more efficient in the general case; 
in some cases, however, **the STL containers may be more efficient**. 
Unlike some other abstractions that Abseil provides, 
these containers should not be considered drop-in replacements for their 
STL counterparts, as there are API and/or contract differences between 
the two sets of containers. 
For example, the Abseil containers often do not guarantee pointer stability 
after insertions or deletions.

> “Pointer stability” means that a pointer to an element remains valid 
> (is not invalidated) so long as the element is present, 
> allowing code to cache pointers to elements even 
> when the underlying container is mutated. 
> Saying that a container has pointer stability is the same as saying
> that it doesn’t move elements in memory; their addresses do not change. 
> Pointer stability/invalidation is the same as reference stability/invalidation. ↩

The Abseil container library defines the following sets of containers:

- Swiss table unordered containers
- B-tree ordered containers

## Hash Tables
The Abseil container library contains a number of useful hash tables generally adhering to the STL container API contract:

* absl::flat_hash_map
* absl::flat_hash_set
* absl::node_hash_map
* absl::node_hash_set

Collectively, these hash tables are known as “Swiss tables” 
and are designed to be replacements for 
`std::unordered_map` and `std::unordered_set` They provide several advantages 
over the std::unordered_* containers:

* Provides C++14 support for C++17 mechanisms such as `try_emplace()` and C++20 mechanisms such as `contains()`. 
* Supports heterogeneous lookup.
* Allows optimizations for `emplace({key, value})` to avoid allocating a pair in most common cases.
* Supports a heterogeneous `std::initializer_list` to avoid extra copies for construction and insertion.
* Guarantees an `O(1)` erase method by returning void instead of an iterator.

