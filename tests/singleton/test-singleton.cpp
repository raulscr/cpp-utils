#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE singleton

#include <boost/test/unit_test.hpp>

#include <singleton/Singleton.h>

using utils::singleton::Singleton;

class DatabaseWriterFake {
    /** This class must will be implemented as a singleton in this example.
     * It'll write data into some database (or not, but imagine that it will).
     */
public:
    DatabaseWriterFake(){
    }

    virtual bool Commit(){
        /** Do nothing at all. But think that we don't want this method to be called by a unit test,
         *  because database operations are slow.
         */
        throw "Must not call DatabaseWriterFake::Commit!"; // Forced error for test proposes
        return true;
    }
};


class MockDatabaseWriterFake : public DatabaseWriterFake {
    /** This mock class must re-implement the original class behavior,
     *  and we want this class to be called instead the original one, even on the singleton
     */

    // Variable for test proposes
    static bool has_called_mocked_commit;
public:
    MockDatabaseWriterFake(){
    }

    bool Commit() override {
        /** Do nothing at all. But think that we don't want this method to be called by a unit test,
         *  because database operations are slow.
         */
        has_called_mocked_commit = true; // increments count for test proposes
        return true;
    }

    /**
     * Method for test proposes
     */
    int HasCalledMockedCommit() const {
        return has_called_mocked_commit;
    }
};

bool MockDatabaseWriterFake::has_called_mocked_commit = false;

// Wrapper must be called before first singleton usage (because it redefines class instantiation)
WRAP_SINGLETON(DatabaseWriterFake, MockDatabaseWriterFake);

class SomeClass {
    /** Imagine that this class do something important, and it call a DatabaseWriterFake to write data on the database.
     *  We want this class to call MockDatabaseWriterFake instead of DatabaseWriterFake, without changing the code.
     *  This is the singleton dependency problem in C++;
     */

public:
    void DoSomething(){
        Singleton<DatabaseWriterFake>::Instance().Commit();
    }
};

BOOST_AUTO_TEST_CASE(SingletonDependenceExampleTest){
    SomeClass().DoSomething();

    // Mocked Commit() must be called once
    BOOST_CHECK_EQUAL(Singleton<MockDatabaseWriterFake>::Instance().HasCalledMockedCommit(), true);
}
