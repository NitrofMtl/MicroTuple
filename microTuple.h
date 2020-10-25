#ifndef MICRO_TUPLE_H
#define MICRO_TUPLE_H


template<size_t idx, typename T>
struct microTupleGetHelper;

template<size_t idx, typename T>
struct microTupleSetHelper;

template<typename ... T>
struct MicroTuple
{
};

template<int ...> struct seq {};

template<int N, int ...S> struct gens : gens<N - 1, N - 1, S...> { };

template<int ...S> struct gens<0, S...>{ typedef seq<S...> type; };



template<typename T, typename ... Rest>
struct MicroTuple<T, Rest ...>
{
    MicroTuple(){};
    MicroTuple(const T& first, const Rest& ... rest)
        : first(first)
        , rest(rest...)
    {}
    
    T first;
    MicroTuple<Rest ... > rest;
    
    template<size_t idx>
    auto get() ->  decltype(microTupleGetHelper<idx, MicroTuple<T,Rest...>>::get(*this))
    {
        return microTupleGetHelper<idx, MicroTuple<T,Rest...>>::get(*this);
    }

    template<size_t idx>
    void set(T value)
    {
        microTupleSetHelper<idx, MicroTuple<T,Rest...>>::set(value, *this);
    }
};

template<typename T, typename ... Rest>
struct microTupleGetHelper<0, MicroTuple<T, Rest ... >>
{
    static T get(MicroTuple<T, Rest...>& data)
    {
        return data.first;
    }
};

template<size_t idx, typename T, typename ... Rest>
struct microTupleGetHelper<idx, MicroTuple<T, Rest ... >>
{
    static auto get(MicroTuple<T, Rest...>& data) ->  decltype(microTupleGetHelper<idx-1, MicroTuple<Rest ...>>::get(data.rest))
    {
        return microTupleGetHelper<idx-1, MicroTuple<Rest ...>>::get(data.rest);
    }
};

template<typename T, typename ... Rest>
struct microTupleSetHelper<0, MicroTuple<T, Rest ... >>
{
    static T set(T value, MicroTuple<T, Rest...>& data)
    {
        data.first = value;
        return data.first;
    }
};

template<size_t idx, typename T, typename ... Rest>
struct microTupleSetHelper<idx, MicroTuple<T, Rest ... >>
{
    static auto set(T value, MicroTuple<T, Rest...>& data) ->  decltype(microTupleGetHelper<idx-1, MicroTuple<Rest ...>>::set(value, data.rest))
    {
        return microTupleGetHelper<idx-1, MicroTuple<Rest ...>>::set(value, data.rest);
    }
};





template <typename ...Args>
class ParamsPack
{
public:
    MicroTuple<Args...> params;
    operator bool() const { return (func) ? true : false; };
    void (*func)(Args...);
private:
    template<int ...S>
    auto callFunc(seq<S...>) -> decltype(this->func(this->params.template get<S>() ...))
    {
    	return func(params.template get<S>() ...);
    }
public:
    auto getPack() -> decltype(this->callFunc(typename gens<sizeof...(Args)>::type()))
    {
        return this->callFunc(typename gens<sizeof...(Args)>::type()); // Item #1
    }

};

#endif