#ifndef CPPUTILS_SINGLETON_SINGLETON_H_
#define CPPUTILS_SINGLETON_SINGLETON_H_


namespace utils {
namespace singleton {
template <typename T>
class Singleton {
public:
    static T& Instance(){
        static T instance;

        return instance;
    }

    Singleton() = delete;
    Singleton& operator = (Singleton & other) = delete;
};

#define WRAP_SINGLETON(T, W)                    \
    template <>                                 \
    T & Singleton<T>::Instance(){               \
        static W instance;                      \
        return instance;                        \
    }
} // namespace singleton
} // namespace utils

#endif // CPPUTILS_SINGLETON_SINGLETON_H_
