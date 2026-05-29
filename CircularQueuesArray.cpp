#include <iostream>
using namespace std;

class Queues
{
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_ARRAY[max];

public:
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue over flow\n" << endl;
            return;
        }

        //CEK APAKAH ANTRIAN KOSONG
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            //jika REAR berada di posisi terakhir maka kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_ARRAY[REAR] = num;
    }

void remove()
{
       // cek apakah antrian kosong
   if (FRONT == -1)
    {
       cout << "Queue underflow";
       return;
    }

    cout << "\nThe element deleted from the queue is: "
         << queue_ARRAY[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
    if (FRONT == REAR)
    {
        FRONT = -1;
        REAR = -1;
    }

    else
    {
        // jika elemen yang dihapus berada di posisi terakhir array,
            // kembali ke awal array
        if (FRONT == max - 1)
                FRONT = 0;
        else
                FRONT = FRONT + 1;
    }
}
