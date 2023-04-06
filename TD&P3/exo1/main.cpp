#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>
#include <map>

constexpr size_t N = 10000;
constexpr size_t LOOP = 1000;

bool premier(int n) {
    for (size_t i = 2; i < n/2 +1; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

void get_premier(size_t n, std::vector<int> &vec) {
    for (size_t i = 0; i < n; i++)
    {
        if (premier(i)) vec.push_back(i);
    }
    
}

void get_premier(size_t n, std::set<int> &set) {
    for (size_t i = 0; i < n; i++)
    {
        if (premier(i)) set.insert(i);
    }  
}

/// @brief get the time of the function passed in parameter
/// @return time
template<typename F>
double get_time(F f) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;

    start = std::chrono::system_clock::now();
    f();
    end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    return elapsed_seconds.count();
}

void vec_to_list(std::vector<int> &vec, std::list<int> &list) {
    while (!vec.empty())
    {
        list.push_back(vec.back());
        vec.pop_back();
    }
}

void list_to_stack(std::list<int> &list, std::stack<int> &stack) {
    while (!list.empty())
    {
        stack.push(list.back());
        list.pop_back();
    }
}

void stack_to_queue(std::stack<int> &stack, std::queue<int> &queue) {
    while (!stack.empty())
    {
        queue.push(stack.top());
        stack.pop();
    }
}

void queue_to_vec(std::queue<int> &queue, std::vector<int> &vec) {
    while (!queue.empty())
    {
        vec.push_back(queue.front());
        queue.pop();
    }
}


void set_to_map(std::set<int> &set, std::map<int, int> &map) {
    for (auto it = set.begin(); it != set.end(); it++)
    {
        map[*it] = *it;
    }
}

void map_to_set(std::map<int, int> &map, std::set<int> &set) {
    for (auto it = map.begin(); it != map.end(); it++)
    {
        set.insert(it->first);
    }
}

void map_to_multiset(std::map<int, int> &map, std::multiset<int> &multiset) {
    for (auto it = map.begin(); it != map.end(); it++)
    {
        multiset.insert(it->first);
    }
}

void multiset_to_multimap(std::multiset<int> &multiset, std::multimap<int, int> &multimap) {
    for (auto it = multiset.begin(); it != multiset.end(); it++)
    {
        multimap.insert(std::pair<int, int>(*it, *it));
    }
}

void multimap_to_set(std::multimap<int, int> &multimap, std::set<int> &set) {
    for (auto it = multimap.begin(); it != multimap.end(); it++)
    {
        set.insert(it->first);
    }
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        os << vec[i] << ", ";
    }
    return os;
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& set) {
    for (auto it = set.begin(); it != set.end(); it++)
    {
        os << *it << ", ";
    }
    return os;
}

void non_associatif_benchmark() {
    std::vector<int> vec;
    get_premier(N, vec);

    std::list<int> list;
    std::stack<int> stack;
    std::queue<int> queue;

    std::cout << "vec to list time: " << get_time([&vec, &list]{ vec_to_list(vec, list); }) << "s" << std::endl;
    std::cout << "list to stack time: " << get_time([&list, &stack]{ list_to_stack(list, stack); }) << "s" << std::endl;
    std::cout << "stack to queue time: " << get_time([&stack, &queue]{ stack_to_queue(stack, queue); }) << "s" << std::endl;
    std::cout << "queue to vec time: " << get_time([&queue, &vec]{ queue_to_vec(queue, vec); }) << "s" << std::endl;

    std::cout << "vec: " << vec << std::endl;


    double time = 0, progress = 0;

    for (size_t i = 0; i < LOOP; i++)
    {
        time += get_time([&vec, &list]{ vec_to_list(vec, list); });
        time += get_time([&list, &stack]{ list_to_stack(list, stack); });
        time += get_time([&stack, &queue]{ stack_to_queue(stack, queue); });
        time += get_time([&queue, &vec]{ queue_to_vec(queue, vec); });
        
        progress = (double)i / (double)LOOP * 100;
        std::cout << "\r" << "[";
        for (size_t j = 0; j < 50; j++)
        {
            if (j < (size_t)progress/2) std::cout << "=";
            else if (j == (size_t)progress/2) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "]" << progress << "%";


    }
    
    std::cout << std::endl << "total time: " << time << "s" << std::endl;
}

void associatif_benchmark() {
    std::set<int> set;
    get_premier(N, set);


    std::map<int, int> map;
    std::multiset<int> multiset;
    std::multimap<int, int> multimap;

    std::cout << "set to map time: " << get_time([&set, &map]{ set_to_map(set, map); }) << "s" << std::endl;
    std::cout << "map to multiset time: " << get_time([&map, &multiset]{ map_to_multiset(map, multiset); }) << "s" << std::endl;
    std::cout << "multiset to multimap time: " << get_time([&multiset, &multimap]{ multiset_to_multimap(multiset, multimap); }) << "s" << std::endl;
    std::cout << "multimap to set time: " << get_time([&multimap, &set]{ multimap_to_set(multimap, set); }) << "s" << std::endl;

    std::cout << "set: " << set << std::endl;

    double time = 0, progress = 0;

    for (size_t i = 0; i < LOOP; i++)
    {
        time += get_time([&set, &map]{ set_to_map(set, map); });
        // time += get_time([&map, &set]{ map_to_set(map, set); });
        // time += get_time([&set, &map]{ set_to_map(set, map); });
        // time += get_time([&map, &set]{ map_to_set(map, set); });
        time += get_time([&map, &multiset]{ map_to_multiset(map, multiset); });
        time += get_time([&multiset, &multimap]{ multiset_to_multimap(multiset, multimap); });
        time += get_time([&multimap, &set]{ multimap_to_set(multimap, set); });
        
        progress = (double)i / (double)LOOP * 100;
        std::cout << "\r" << "[";
        for (size_t j = 0; j < 50; j++)
        {
            if (j < (size_t)progress/2) std::cout << "=";
            else if (j == (size_t)progress/2) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "]" << progress << "%";
    }
    
        std::cout << std::endl << "total time: " << time << "s" << std::endl;
}



int main() {
    std::cout << premier(8) << std::endl;
    std::cout << premier(11) << std::endl;

    non_associatif_benchmark();

    associatif_benchmark();

    return 0;
} 