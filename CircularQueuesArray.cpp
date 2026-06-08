
/**
 * @mainpage Documentation Circular Queues
 * 
 * @section introduction Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations
 * project ini memiliki beberapa operasi antara lain:
 * 1.Insert
 * 2.Delete
 * 3.Display
 * 
 * @section Cara Penggunaan
 * berikut beberapa Menu yang bisa di gunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - Nama : Huda Nugraha
 * - Nim : 20250140196
 * - Kelas : D
 * 
 * @brief
 * @version 1.0
 * @date 2026-06-08
 * 
 * @copyright huda.nugraha.ft25@mail.umy.ac.id
 * 
 */

#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 * 
 *  
 */
class Queues
{
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_ARRAY[max];

public:
    /**
     * @brief construct a new queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukkan data dalam antrian
     * data di masukkan dalam variable queue_array
     */
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

    /**
     * @brief method untuk menghapus data dalam antrian
     * data di hapuskan dari dalam variable queue_array
     */
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

/**
 * @brief method untuk menampilkan data dalam antrian
 * data di tampilkan dari dalam variable queue_array
 */
void display()
{
    int FRONT_Position = FRONT;  ///< variable front_position untuk menandakan posisi element pertama pada variable front
    int REAR_Position = REAR;    ///< variable rear_position untuk menandakan posisi element terakhir pada variable rear


     // cek apakah antrian kosong
    if (FRONT_Position == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "\nElements in the queue are...\n";

    // jika FRONT <= REAR, iterasi dari FRONT hingga REAR
    if (FRONT_Position <= REAR_Position)
    {
        while (FRONT_Position <= REAR_Position)
        {
            cout << queue_ARRAY[FRONT_Position] << " ";
            FRONT_Position++;
        }

        cout << endl;
    }
    else
    {
        // jika FRONT > REAR, iterasi dari FRONT hingga akhir array
        while (FRONT_Position <= max - 1)
        {
            cout << queue_ARRAY[FRONT_Position] << " ";
            FRONT_Position++;
        }

        // iterasi dari awal array hingga REAR
        FRONT_Position = 0;
        while (FRONT_Position <= REAR_Position)
        {
            cout << queue_ARRAY[FRONT_Position] << " ";
            FRONT_Position++;
        }

        cout << endl;
    }
}
};

/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */
int main()
{
    Queues q;///< objek untuk menggunakan member yang ada pada class queues
    char ch;///< variable ch untuk menyimpan pilihan pada menu yang di berikan

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement Insert Operation" << endl;
            cout << "2. Implement Delete Operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;

            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }

            case '2':
            {
                q.remove();
                break;
            }

            case '3':
            {
                q.display();
                break;
            }

            case '4':
            {
                return 0;
            }

            default:
            {
                cout << "Invalid option!!!" << endl;
                break;
            }
            }
        }
        catch (exception &ex)
        {
            cout << "Check for the values entered." << endl;
        }
    }

    return 0;
}
