#ifndef CPPSLX_HELPER_MACROS_HPP
#define CPPSLX_HELPER_MACROS_HPP

#if defined(__cpp_static_call_operator)
#define CPPSLX_STATIC_CALL          static
#define CPPSLX_STATIC_CALL_CONST
#else
#define CPPSLX_STATIC_CALL          
#define CPPSLX_STATIC_CALL_CONST    const
#endif

#endif//CPPSLX_HELPER_MACROS_HPP
