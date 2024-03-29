#pragma once

#include <unordered_map>
#include <list>
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <sstream>

template<typename key_t, typename value_t>
class SimpleCache {
public:
	typedef typename std::pair<key_t, std::pair<value_t, size_t>> key_value_pair_t;
	typedef typename std::list<key_value_pair_t>::iterator list_iterator_t;
	typedef typename std::unordered_map<key_t, list_iterator_t> key_item_map_t;
	typedef typename std::list<key_value_pair_t> item_list_t;

	SimpleCache(size_t max_size, bool lru_mode = true)
		: _max_size(max_size), _lru_mode(lru_mode)
	{
		assert(max_size > 0);
	}

	const value_t& get(const key_t& key)
	{
		auto it = _cache_items_map.find(key);
		// 未找到，抛出异常
		if (it == _cache_items_map.end())
		{
			throw std::range_error("LRUCache Error: There is no such key of cache.");
		}
		else
		{
			if (_lru_mode)
			{
				// 移动到最前面
				_cache_items_list.splice(_cache_items_list.begin(), _cache_items_list, it->second);
			}
			return it->second->second.first;
		}
	}

	void put(const key_t& key, const value_t& value, size_t weight = 1)
	{
		// 元素大小超过cache的_max_size，抛出异常
		if (weight > _max_size)
		{
			throw std::range_error("LRUCache Error: Too big to put.");
		}

		// 放入元素
		auto it = _cache_items_map.find(key);
		if (it != _cache_items_map.end())
		{
			_curr_size -= it->second->second.second;
			_cache_items_list.erase(it->second);
			_cache_items_map.erase(it);
		}

		if (_lru_mode)
		{
			// 添加元素到最前面
			_cache_items_list.push_front(key_value_pair_t(key, std::make_pair(value, weight)));
			_cache_items_map[key] = _cache_items_list.begin();
			_curr_size += weight;
		}
		else
		{
			// 添加元素到最后面
			_cache_items_list.push_back(key_value_pair_t(key, std::make_pair(value, weight)));
			_cache_items_map[key] = std::prev(_cache_items_list.end());
			_curr_size += weight;
		}

		// 超出则缩减
		if (_lru_mode)
		{
			// 从尾向前缩减 cache 的到合法尺寸
			while (_curr_size > _max_size)
			{
				auto last = _cache_items_list.end();
				last--;
				_curr_size -= last->second.second;
				_cache_items_map.erase(last->first);
				_cache_items_list.pop_back();
			}
		}
		else
		{
			// 从头向后缩减 cache 的到合法尺寸
			while (_curr_size > _max_size)
			{
				auto beg = _cache_items_list.begin();
				_curr_size -= beg->second.second;
				_cache_items_map.erase(beg->first);
				_cache_items_list.pop_front();
			}
		}
	}

	size_t size() const
	{
		return _curr_size;
	}

	bool exists(const key_t& key) const
	{
		return _cache_items_map.find(key) != _cache_items_map.end();
	}

	void debug_print() const
	{
		std::stringstream ss;
		for (auto it = _cache_items_list.cbegin(); it != _cache_items_list.end(); ++it)
		{
			ss << "(" << it->first << ", " << it->second.first << ")" << ", ";
		}
		ss << "\n";
		std::cout << ss.str();
	}

private:
	bool _lru_mode{ true };
	size_t _max_size;
	size_t _curr_size{ 0 };
	item_list_t _cache_items_list;
	key_item_map_t _cache_items_map;
};


void test_simple_cache()
{
	std::cout << ">>>>>>>>>>>>>>>>>>LRU test<<<<<<<<<<<<<<<<<<<<<<<<\n\n";

	SimpleCache<std::string, int> lru{ 5, true };

	try
	{
		lru.get(std::string("name"));
	}
	catch (std::range_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	lru.put(std::string("age"), 100, 2);
	lru.put(std::string("money"), 123, 1);
	lru.debug_print();
	lru.put(std::string("book"), 10, 2);
	lru.debug_print();
	lru.get(std::string("money"));
	lru.debug_print();
	lru.put(std::string("sport"), 1000, 2);
	lru.debug_print();

	try {
		lru.put(std::string("devil"), 1, 1000);
		lru.debug_print();
	}
	catch (std::range_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n>>>>>>>>>>>>>>>>>>FIFO test<<<<<<<<<<<<<<<<<<<<<<<<\n\n";

	SimpleCache<std::string, int> fifo{ 5, false };
	fifo.put(std::string("age"), 100, 2);
	fifo.put(std::string("money"), 123, 1);
	fifo.debug_print();
	fifo.put(std::string("book"), 10, 2);
	fifo.debug_print();
	fifo.put(std::string("money"), 234, 1);
	fifo.debug_print();
	fifo.get(std::string("book"));
	fifo.debug_print();
	fifo.put(std::string("sport"), 1000, 2);
	fifo.debug_print();
}




