#ifndef CPPUTILS_SINGLETON_SINGLETON_H_
#define CPPUTILS_SINGLETON_SINGLETON_H_

namespace utils {
namespace adaptor {
/**
 * @brief Interface to adapt one type/class to another
 * @note from(F&) must be implemented on derived adaptor class
 */
template <typename F, typename T>
class Adaptor : public T {
public:
    explicit Adaptor(const T& other) :
        T(other){
    }

    virtual T& from(const F& base) = 0;
};
} // namespace singleton
} // namespace utils

#endif // CPPUTILS_SINGLETON_SINGLETON_H_
