/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:10:06 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 15:41:25 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
    //std::cout << "PergmeMe destroyed" << std::endl;
}

PmergeMe::~PmergeMe()
{
    //std::cout << "PergmeMe destroyed" << std::endl;
}
PmergeMe::PmergeMe(const PmergeMe &src)
{
    // if((src->a).empty())
    //     this->a = src->a;
    // if((src->b).empty())
    //     this->b = src->b;
    //return (this);
}
int PmergeMe::init_containers(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        std::string s = std::string(argv[i]);
        for (size_t i = 0; i < s.size(); ++i)
            if (!std::isdigit(s[i]) && !(s[i] == '-' && i == 0))
                return (1); 
        if(s.length() > 10)
                return (2);
        this->a.push_back(
            std::atoi((argv[i]))
        );
        this->b.push_back(
            std::atoi((argv[i]))
        );
    }
    this->count = argc;
    return (0);
}
// insertion Sort function
template <typename T>
static void insertionSort(T& container)
{
    typename T::iterator i, j;
    for (i = container.begin() + 1; i != container.end(); ++i)
    {
        typename T::value_type key = *i;
        j = i;
        while (j > container.begin() && *(j - 1) > key)
        {
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}


// merge two sorted containers optimally using Ford-Johnson
// working for containers w iterator and push_back()
// L = left, R = right
template <typename T>
static void fordJohnsonMerge(T& L, T& R, T& result)
{
    typename T::iterator L_ = L.begin(), R_ = R.begin();
    while (L_ != L.end() && R_ != R.end())
    {
        if (*L_ <= *R_) {
            result.push_back(*L_);
            ++L_;
        } else {
            result.push_back(*R_);
            ++R_;
        }
    }
    // Add remaining elements
    result.insert(result.end(), L_, L.end());
    result.insert(result.end(), R_, R.end());
}


// Merge-Insertion Sort algorithm using Ford-Johnson Merge
// this threshold of 43 is based on empirical testing showing that, 
// for arrays with fewer than 43 elements, insertion sort is faster than overhead of recursive merges
// ie for 3000 elements 
//   - (treshold=10 -> 0.00102 us)
//   - (treshold=43 -> 0.00081 us)
template <typename T>
static void mergeInsertionSort(T& container)
{
    const size_t n = container.size();
    if (n <= 43) // threshold for using insertion sort
    { 
        insertionSort(container);
    }
    else
    {
        // split the container into two halves
        const size_t mid = n / 2;
        T left(container.begin(), container.begin() + mid);
        T right(container.begin() + mid, container.end());

        // recursively sort [both halves]
        mergeInsertionSort(left);
        mergeInsertionSort(right);

        // merge the sorted halves using Ford-Johnson
        T result;
        fordJohnsonMerge(left, right, result);

        container = result;
    }
}


void PmergeMe::display_inf(void)
{
    std::cout << "\033[33mBefore:\t";
    for(unsigned long i = 0; i < this->a.size(); i++)
    {
        std::cout << this->a[i] << " ";
    }
    double time_taken_a, time_taken_b;
    clock_t start, end;

    start = clock();
    mergeInsertionSort(this->a);
    end = clock();
    time_taken_a = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    mergeInsertionSort(this->b);
    end = clock();
    time_taken_b = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "\033[32m\nAfter:\t";
    for(unsigned long i = 0; i < this->a.size(); i++)
    {
        std::cout << this->a[i] << " ";
    }
    mergeInsertionSort(this->a);
    std::cout << "\n\033[36mTime to process a range of "<< this->count << " elements "
        << "with \e[1mstd::vector\e[0m = "
        << std::fixed << std::setprecision(5)  // Set to 5 decimal places 
        << time_taken_a << "µseconds" << std::endl;
    std::cout << "\n\033[36mTime to process a range of "<< this->count << " elements "
        << "with \e[1mstd::deque\e[0m = "
        << std::fixed << std::setprecision(5)  // Set to 5 decimal places 
        << time_taken_a << "µseconds" << std::endl;
    std::cout << "\033[37mTimes have high chances of being equals since i used <T>functions that use <T>containers"
    << std::endl;
    std::cout << std::endl;
}
