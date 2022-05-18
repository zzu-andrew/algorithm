/*
 * LRUCache又称为最近很少使用算法，不是说这个算法最近很少使用，是算法的名字叫做最近很少使用。
 * LRU是 Least Recently Used的缩写，即最近很少使用，是一种常用的页面置换算法，
 * 选择最近很久未使用的页面予以淘汰。LRUCache是一种缓存策略，持有的是强引用，但是会控制在一个峰值下。
 * 它内部维护了一个队列(允许插队的队列)，每当从中取出一个值时，该值就移动到队列的头部。
 * 当缓存已满而继续添加时，会将队列尾部的值移除，方便GC。LRUCache用于内存缓存，
 * 在避免程序发生OOM和提高执行效率有着良好表现。
 * */


#ifndef ALGORITHM_LRU_CAACHE_H
#define ALGORITHM_LRU_CAACHE_H
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <list>
#include <unordered_map>
#include <cstddef>

using namespace std;

template<typename key_t, typename value_t>
class LruCache {
public:
    typedef typename std::pair<key_t, value_t> key_value_pair_t;
    typedef typename std::list<key_value_pair_t>::iterator list_iterator_t;

    explicit LruCache(size_t maxSize) :
            m_maxSize(maxSize) {
    }

    void Put(const key_t& key, const value_t& value) {
        auto it = m_cacheItemsMap.find(key);
        m_cacheItemsList.push_front(key_value_pair_t(key, value));
        if (it != m_cacheItemsMap.end()) {
            m_cacheItemsList.erase(it->second);
            m_cacheItemsMap.erase(it);
        }
        m_cacheItemsMap[key] = m_cacheItemsList.begin();

        if (m_cacheItemsMap.size() > m_maxSize) {
            auto last = m_cacheItemsList.end();
            last--;
            m_cacheItemsMap.erase(last->first);
            m_cacheItemsList.pop_back();
        }
    }

    value_t Get(const key_t& key) {

        auto it = m_cacheItemsMap.find(key);
        if (it == m_cacheItemsMap.end()) {
            return value_t{};
        } else {
            // 将最新的节点提前
            m_cacheItemsList.splice(m_cacheItemsList.begin(),
                                    m_cacheItemsList, it->second);
            return it->second->second;
        }
    }

    template<typename Add>
    void UpdateCache(const key_t& key, Add add) {

        auto it = m_cacheItemsMap.find(key);
        if (it == m_cacheItemsMap.end()) {
        } else {
            // 将最新的节点提前
            m_cacheItemsList.splice(m_cacheItemsList.begin(), m_cacheItemsList, it->second);
            add(it->second->second);
        }
    }

    bool Exists(const key_t& key) const {
        return m_cacheItemsMap.find(key) != m_cacheItemsMap.end();
    }

    size_t Size() const {
        return m_cacheItemsMap.size();
    }

    // TODO：优化 采用加锁引用的方式避免复制
    std::list<key_value_pair_t> GetLruList() const {
        return m_cacheItemsList;
    }

private:
    std::list<key_value_pair_t> m_cacheItemsList;
    std::unordered_map<key_t, list_iterator_t> m_cacheItemsMap;
    size_t m_maxSize;
};


#endif //ALGORITHM_LRU_CAACHE_H
