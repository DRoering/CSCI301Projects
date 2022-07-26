#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ostream>
#include <cstring>

using namespace std;


class Q
{

public:
    typedef int Item;

    static const int CAPACITY = 500;
    Q();

    void enqueue(Item entry);
    Item dequeue();
    int sizeq(){return countq;}
    bool emptyq(){return countq == 0;}

private:
    int next_Index(int i){return((i + 1) % CAPACITY);}
    int frontq;
    int rearq;
    int countq;
    Item line[CAPACITY];

};

Q::Q()
{
    frontq = 0;
    rearq = CAPACITY - 1;
    countq = 0;
}

void Q::enqueue(Item entry)
{
    rearq = next_Index(rearq);
    line[rearq] = entry;
    ++countq;
}

Q::Item Q::dequeue()
{
    Item it;
    it = line[frontq];
    frontq = next_Index(frontq);
    --countq;
}


//ostream& operator<<(ostream& out.s, Q q)
//{
//    Q::Item it;
//    int m;
//    m = q.sizeq();
//    for(int i = 0; i < m; i++)
//    {
//        it = q.dequeue();
//        out.s << it << ' ';
//        q.enqueue(it);
//    }
//}





int shortest_queue(Q q[], int queuecount)
{
    int shortest = 0;
    for (int i = 1; i < queuecount; ++i)
    {
        if(q[i].sizeq() < q[shortest].sizeq())
            shortest = i;
    }
    return shortest;
}

int queue_total(Q q[], int queuecount)
{
    int custcount = 0;
    for (int i = 0; i < queuecount; ++i)
        custcount += q[i].sizeq();
    return custcount;
}

int main()
{

    int trans_time = 0;
    int countq = 0;
    int entry_time;
    int wait_sum = 0;
    int wait_time = 0;
    int seed;
    int ARV_PROB;
    int MAX_TRANS_TIME;
    int DURATION;
    int queuecount;
    int shortline;
    int temp;

    cout << "Enter these parameters of the simulation:" << endl;
    cout << " The number of queue/server pairs: ";
    cin >> queuecount;
    Q line[queuecount];
    cout << " The probability that a customer arrives in one tick (%): ";
    cin >> ARV_PROB;
    cout << " The maximum duration of a transaction in ticks: ";
    cin >> MAX_TRANS_TIME;
    cout << " The duration of the simulation in ticks: ";
    cin >> DURATION;
    cout << "Enter a random number seed: ";
    cin >> seed;
    srand(seed);

    for (int time = 0; time < DURATION; ++time)
    {
        if ( rand() % 100 < ARV_PROB )
        {
            shortline = shortest_queue(line, queuecount);
            line[shortline].enqueue(time);
        }

        if ( trans_time == 0 )
        {

            if ( !line[time].emptyq() )
            {
                entry_time = line[time].dequeue();
                temp = (time - entry_time);

                if(temp > wait_time)
                    wait_time = temp;

                wait_sum += (time - entry_time);
                ++countq;
                trans_time = (rand() % MAX_TRANS_TIME) + 1;
            }
        }
        else
        {
            --trans_time;
        }
        cout << setw(4) << time << setw(4) << trans_time << "  " << line << endl;
    }

    cout << countq << " customers waited an average of ";
    cout << wait_sum / countq << " ticks." << endl;
    cout << "The longest time a customer waited was " << wait_time << " ticks." << endl;
    cout << queue_total(line, queuecount) << " customers remain in the lines." << endl;

    return 0;
}
