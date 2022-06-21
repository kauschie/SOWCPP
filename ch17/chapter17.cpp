****************************
    Intro to the STL
****************************

    Concept:
        The standard template library (STL) is an extensive collection of templates
        for useful data structures and algorithms


Containers:
    *   class templates for objects that store and organize data

Iterators:
    *   class templates for objects that behave like pointers, and are used to 
        access individual data elements in a container
    
Algorithms
    *   Function templates that perform various operations on elements of containers



********************************
            Containers
********************************

-   Two types of containers:

        Sequence:
            * stores data sequentially in memory in a similar fashion to an array

        Associative:   
            * stores nonsequentially that makes it faster to locate elements

::::::Sequence Containers:::::

    array   - fixed size container that is similar to an array
    deque   - double ended queue. Like a vector but designed to quickly add and 
                remove things from both the front and the back
    forwarded_list  - singly linked list of data elements
                - vals are inserted / removed from any position
    list    - doubly linked list of data elements
                - vals are inserted / removed from any position
    vector  - container that works like an array that adjusts its size automatically


::::::Associative Containers::::::::::

    set     - stores set of unique vals that are sorted. No duplicates are allowed
    multiset    - stores set of unique vals that are sorted. Duplicates ARE allowed
    map     - maps a set of keys to data elements
                    - one key per data element
                    - duplicates not allowed
                    - elements are sorted by keys
    multimap    - maps a set of keys to data elements. 
                    - Many keys per data element are allowed.
                    - Elements are sorte in order of keys
                    - duplicates allowed
    unordered_set   - like a set but unsorted
    unordered_multiset - like a multiset except unsorted
    unordered_map   - like a map but unsorted
    unordered_multimap  - like a multimap but unsorted

:::::::::::Container Adapter Classes:::::::::::::
    
    stack   - stores elements in a deque 
            - Last In First Out  (LIFO)
    
    queue   - stores elements in a deque
            - First In First Out (FIFO)
    
    priority_queue  - stores elements in a vector
                    - retrieved element always has the greatest value
        
