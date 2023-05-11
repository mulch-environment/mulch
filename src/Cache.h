// CACHE_H


#ifndef __mulch__Cache_h__
#define __mulch__Cache_h__

#include <map>
#include "Object.h"

namespace mulch {

    template<typename T>
    class Cache {
    public:
        static std::pair<T*, int> cacheByPrimaryId(int id, Database* db) 
        {
            // Check if the object with the given ID is already in the cache
            auto it = cache.find(id); // cache is an std::map object
            if (it != cache.end()) {
                std::cout << "Returning cached " << typeid(T).name() << " object for ID " << id << std::endl;
                return std::make_pair(it->second, id);
            }

            // If the object is not in the cache, create a new one
            T* newObject = new T();

            // Retrieve data for the given ID and populate the newModel object
            newObject->retrieveExisting(id, db);

            // Add the new object to the cache
            cache[id] = newObject;

            return std::make_pair(newObject, id);
        }
       	friend class Object;
    private:
        static std::map<int, T*> cache;
    };

    // Define the static cache map
    template<typename T>
    std::map<int, T*> Cache<T>::cache; 

} 

#endif // CACHE_H