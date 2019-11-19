//
// Created by thekatze on 20/07/2019.
//

#ifndef SHVRD_RESOURCEMANAGER_H
#define SHVRD_RESOURCEMANAGER_H

#include <map>
#include <memory>
#include <string>

// TODO: Make key class templated, too
template<class Resource>
class ResourceManager {
    std::map<std::string, std::shared_ptr<Resource>> m_resourceMap;
public:
    ResourceManager();
    ~ResourceManager();

    void add(const std::string& filePath, std::shared_ptr<Resource> resource);
    std::shared_ptr<Resource> get(const std::string& filePath) const;

    unsigned int size() const;

    void clear();
};

template<class Resource>
ResourceManager<Resource>::ResourceManager()
    : m_resourceMap() {

}

template<class Resource>
ResourceManager<Resource>::~ResourceManager() {
    clear();
}

template<class Resource>
void ResourceManager<Resource>::add(const std::string &filePath, std::shared_ptr<Resource> resource) {
    m_resourceMap.insert(std::make_pair(filePath, resource));
}

template<class Resource>
std::shared_ptr<Resource> ResourceManager<Resource>::get(const std::string &filePath) const {
    auto iterator = m_resourceMap.find(filePath);

    if (iterator == m_resourceMap.end()) {
        return nullptr;
    }

    return iterator->second;
}

template<class Resource>
unsigned int ResourceManager<Resource>::size() const {
    return m_resourceMap.size();
}

template<class Resource>
void ResourceManager<Resource>::clear() {
    m_resourceMap.clear();
}


#endif //SHVRD_RESOURCEMANAGER_H
