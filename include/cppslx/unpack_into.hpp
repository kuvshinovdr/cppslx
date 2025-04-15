#ifndef CPPSLX_UNPACK_INTO_HPP
#define CPPSLX_UNPACK_INTO_HPP

#include <tuple>
#include <type_traits>


namespace cppslx
{

	/// Wraps a function of several arguments into a function accepting a tuple.
	template <typename Func>
	struct unpack_into
	{
		Func func;

		template <typename Tuple>
		constexpr decltype(auto) operator()(Tuple&& tuple) const
			noexcept(noexcept(std::apply(func, std::forward<Tuple>(tuple))))
		{
			return std::apply(func, std::forward<Tuple>(tuple));
		}

		template <typename Tuple>
		constexpr decltype(auto) operator()(Tuple&& tuple)
			noexcept(noexcept(std::apply(func, std::forward<Tuple>(tuple))))
		{
			return std::apply(func, std::forward<Tuple>(tuple));
		}
	};
	
}

#endif//CPPSLX_UNPACK_INTO_HPP
