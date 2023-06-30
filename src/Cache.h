// CACHE_H


#ifndef __mulch__Cache_h__
#define __mulch__Cache_h__

#include <map>
#include "Object.h"

namespace mulch {

    template<typename T>
    class Cache {
    public:
        static T* cacheByPrimaryId(int id, Database* db) 
        {
        	std::cout << "I'm in Cahce!" <<std::endl;
            // Check if the object with the given ID is already in the cache
            auto it = cache.find(id); // cache is an std::map object
            if (it != cache.end()) {
                std::cout << "Returning cached " << typeid(T).name() << " object for ID " << id << std::endl;
                return it->second;
            }

            // If the object is not in the cache, create a new one
            T* newObject = new T();

            // Retrieve data for the given ID and populate the newObject object
            newObject->retrieveExisting(id, db);
            // Add the new object to the cache
            cache[id] = newObject;
            return newObject;
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