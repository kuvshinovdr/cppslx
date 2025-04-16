#ifndef CPPSLX_N_ARY_RELATION_HPP
#define CPPSLX_N_ARY_RELATION_HPP

#include <concepts>
#include <type_traits>

namespace cppslx
{

    /// Make ApplyTo<T, T, ..., T>, where T repeats N times.
    template <
        typename    T, 
        size_t      N, 
        template <typename...> typename ApplyTo, 
        typename... Head
        >
    struct repeat_type 
    {
        using type = 
            typename repeat_type<T, N - 1, ApplyTo, Head..., T>::type;
    };

    template <
        typename    T, 
        template <typename...> typename ApplyTo, 
        typename... Head
        >
    struct repeat_type<T, 0, ApplyTo, Head...>
    {
        using type = ApplyTo<Head...>;
    };

    /// A shortcut for typename::repeat_type<T, N, ApplyTo, ...>::type.
    template <
        typename    T, 
        size_t      N, 
        template <typename...> typename ApplyTo,
        typename... Head
        >
    using repeat_type_t =
        typename repeat_type<T, N, ApplyTo, Head...>::type;


    /// Check if F is invocable as F(T, T, ..., T) where T repeats N times.
    template <
        typename F,
        typename T,
        size_t   N
        >
    struct is_n_ary_invocable
        : repeat_type_t<T, N, std::is_invocable, F> {};

    /// A shortcut for typename is_n_ary_invocable<F, T, N>::type.
    template <
        typename F,
        typename T,
        size_t   N
        >
    using is_n_ary_invocable_t =
        typename is_n_ary_invocable<F, T, N>::type;

    /// A shortcut for is_n_ary_invocable_t<F, T, N>::value.
    template <
        typename F,
        typename T,
        size_t   N
        >
    inline constexpr bool is_n_ary_invocable_v =
        is_n_ary_invocable_t<F, T, N>::value;


    /// Get the result type of evaluating F(T, T, ..., T) call, where T repeats N times.
    template <
        typename F,
        typename T,
        size_t N
        >
    struct n_ary_invoke_result
        : repeat_type<T, N, std::invoke_result, F>::type {};

    /// A shortcut for typename n_ary_invoke_result<F, T, N>::type.
    template <
        typename F,
        typename T,
        size_t N
        >
    using n_ary_invoke_result_t
        = typename n_ary_invoke_result<F, T, N>::type;


    /// Check if F is callable as F(T, T, ..., T) where T repeats N times and produces something bool-testable.
    template <
        typename F,
        typename T,
        size_t N
        >
    concept n_ary_relation =
        is_n_ary_invocable_v<F, T, N> &&
        std::convertible_to<n_ary_invoke_result_t<F, T, N>, bool>;

}

#endif//CPPSLX_N_ARY_RELATION_HPP
