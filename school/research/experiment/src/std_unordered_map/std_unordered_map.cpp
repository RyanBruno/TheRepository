/* A unordered_map implementation as
 * a proxy for the STL's unordered_map
 * with C bindings.
 */
#include <unordered_map>
#include <stdexcept>

typedef void* unordered_map;

extern "C" unordered_map unordered_map_create()
{
    return (void*) new std::unordered_map<uint64_t, void*>();
}

extern "C" void unordered_map_free(unordered_map um)
{
    delete ((std::unordered_map<uint64_t, void*>*) um);
}

extern "C" void unordered_map_add(unordered_map um, uint64_t k, void* i)
{
    auto rc = ((std::unordered_map<uint64_t, void*>*) um)->insert(std::make_pair(k, i));
    /*if (!rc.second)
        printf("DID NOT INSERT %lu, %s\n", k, i);*/
}

extern "C" void* unordered_map_get(unordered_map um, uint64_t k)
{
    try {
        return ((std::unordered_map<uint64_t, void*>*) um)->at(k);
    } catch (const std::out_of_range& e) {
        return NULL;
    }
}

/* Used to start a loop across all items in
 * the unordered_map. Sets 'k' and 'i' to
 * the first key and value (respectively) in
 * 'um'. Return 1 on success and 0 if the map
 * is empty.
 */
extern "C" int unordered_map_first(unordered_map um, uint64_t* k, void** i)
{
    auto it = ((std::unordered_map<uint64_t, void*>*) um)->begin();

    if (it == ((std::unordered_map<uint64_t, void*>*) um)->end())
        return 0;

    *k = it->first;
    *i = it->second;

    return 1;
}

/* After unordered_map_begin is called this
 * function returns the first item in the
 * unordered_map_it 'um_it' and returns it in
 * 'k' and 'i'. Will return 1 on success and 0
 * when the end has been reached.
 */
extern "C" int unordered_map_next(unordered_map um, uint64_t* k, void** i)
{
    auto it = ((std::unordered_map<uint64_t, void*>*) um)->find(*k);

    if (it == ((std::unordered_map<uint64_t, void*>*) um)->end()) {
        return 0;
    }

    if (++it == ((std::unordered_map<uint64_t, void*>*) um)->end()) {
        return 0;
    }

    *k = it->first;
    *i = it->second;

    return 1;
}

extern "C" void unordered_map_erase(unordered_map um, uint64_t k)
{
    ((std::unordered_map<uint64_t, void*>*) um)->erase(k);
}

extern "C" size_t unordered_map_size(unordered_map um)
{
    return (size_t) ((std::unordered_map<uint64_t, void*>*) um)->size();
}
