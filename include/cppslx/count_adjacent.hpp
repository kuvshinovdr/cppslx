#ifndef CPPSLX_COUNT_ADJACENT_HPP
#define CPPSLX_COUNT_ADJACENT_HPP

#include <ranges>
#include <functional>

#include "n_ary_relation.hpp"
#include "helper_macros.hpp"
#include "unpack_into.hpp"

// TODO: add Ranges-style projection.

namespace cppslx
{
    
    /// Count how often pred(item1, item2, ..., itemN) are true, where items are adjacent items of the range.
    template <
        size_t N,
        std::ranges::forward_range Range,
        n_ary_relation<std::ranges::range_reference_t<Range>, N> Pred
        >
    [[nodiscard]] constexpr auto count_adjacent(Range const& range, Pred&& pred)
        -> std::ranges::range_difference_t<Range>
    {
        return ranges::count_if(
            views::adjacent<N>(range), 
            unpack_into{std::forward<Pred>(pred)});
    }
    
    /// Count how often pred(item1, item2) are true, where items are adjacent items of the range.
    template <
        std::ranges::forward_range Range,
        n_ary_relation<std::ranges::range_reference_t<Range>, 2> Pred = std::equal_to<>
        >
    [[nodiscard]] constexpr auto count_pairwise(Range const& range, Pred&& pred = {})
        -> std::ranges::range_difference_t<Range>
    {
        return ranges::count_if(
            views::pairwise(range), 
            unpack_into{std::forward<Pred>(pred)});
    }
    
}

#endif//CPPSLX_COUNT_ADJACENT_HPP
