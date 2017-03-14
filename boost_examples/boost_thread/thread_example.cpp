#include <boost/thread.hpp>
#include <iostream>

using namespace std;

void ThreadFunction1()
{
    int counter = 0;

    for(;;)
    {
        cout << "thread 1 iteration " << ++counter << " Press Enter to stop" << endl;

        try
        {
            // Sleep and check for interrupt.
            // To check for interrupt without sleep,
            // use boost::this_thread::interruption_point()
            // which also throws boost::thread_interrupted
            boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        }
        catch(boost::thread_interrupted&)
        {
            cout << "Thread 1 is stopped\r\n" << endl;
            return;
        }
    }
}


void ThreadFunction2()
{
    int counter = 0;

    for(;;)
    {
        cout << "thread 2 iteration " << ++counter << " Press Enter to stop" << endl;

        try
        {
            // Sleep and check for interrupt.
            // To check for interrupt without sleep,
            // use boost::this_thread::interruption_point()
            // which also throws boost::thread_interrupted
            boost::this_thread::sleep(boost::posix_time::milliseconds(750));
        }
        catch(boost::thread_interrupted&)
        {
            cout << "Thread 2 is stopped\r\n" << endl;
            return;
        }
    }
}

int main()
{
    // Start thread
    boost::thread t1(&ThreadFunction1);
    boost::thread t2(&ThreadFunction2);

    // Wait for Enter 
    char ch;
    cin.get(ch);

    // Ask thread to stop
    t1.interrupt();
    t2.interrupt();

    // Join - wait when thread actually exits
    t1.join();
    t2.join();
    // cout << "main: thread ended" << endl;

    return 0;
}