#include "Task2.h"

#include <iostream>
#include <new>

class Vector
{
    public:
    enum State
    {
        OK,NO_MEMORY,BAD_BOUNDS
    };

    private:
    float* data;
    int size;
    State state;

    public:
    static int count;
    Vector()
    {
        size = 1;
        data = new(std::nothrow)  float[size];
        if (!data)
            state = NO_MEMORY;

        data[0] = 0.0f;

        state = OK;
        count++;
    }

    Vector(int amount)
    {
        size = amount;
        data = new(std::nothrow)  float[size];
        if (!data)
            state = NO_MEMORY;

        for (int i = 0; i < size; i++)
            data[i] = 0.0f;

        state = OK;
        count++;
    }

    Vector(int amount, float init)
    {
        size = amount;
        data = new(std::nothrow)  float[size];
        if (!data)
            state = NO_MEMORY;

        for (int i = 0; i < size; i++)
            data[i] = init;

        state = OK;
        count++;
    }

    Vector(const Vector& vector)
    {
        size = vector.size;
        data = new(std::nothrow)  float[size];
        if (!data)
            state = NO_MEMORY;

        for (int i = 0; i < size; i++)
            data[i] = vector.data[i];

        state = OK;
        count++;
    }

    ~Vector()
    {
        delete[] data;
        count--;
    }

    void set(int index, float value)
    {
        if (index >= size)
        {
            state = BAD_BOUNDS;
            return;
        }

        data[index] = value;
        state = OK;
    }

    float get(int index)
    {
        if (index >= size)
        {
            state = BAD_BOUNDS;
            return 0.0f;
        }

        state = OK;
        return data[index];
    }

    void printVector()
    {
        std::cout << " { ";
        for (int i = 0; i < size; i++)
        {
            if (i > 0)
                std::cout << ", ";
            std::cout << data[i];
        }
        std::cout << " }" << std::endl;
    }

    Vector Add(Vector& vector)
    {
        int smallestSize = size < vector.size ? size : vector.size;
        Vector vct(smallestSize);

        for (int i = 0; i < smallestSize; i++)
            vct.data[i] = data[i] + vector.data[i];

        return vct;
    }

    Vector Sub(Vector& vector)
    {
        int smallestSize = size < vector.size ? size : vector.size;
        Vector vct(smallestSize);

        for (int i = 0; i < smallestSize; i++)
            vct.data[i] = data[i] - vector.data[i];

        return vct;
    }

    void Mul(long value)
    {
        for (int i = 0; i < size; i++)
            data[i] = data[i] * value;
    }

    float length()
    {
        float result = 0.0f;
        for (int i = 0; i < size; i++)
            result += data[i];

        return result;
    }

    bool LargerThan(Vector& vector)
    {
        return length() > vector.length();
    }

    bool LessThan(Vector& vector)
    {
        return length() < vector.length();
    }

    bool equal(Vector& vector)
    {
        return length() == vector.length();
    }

    State getState()
    {
        return state;
    }
};

int Vector::count = 0;

void task2()
{
    std::cout << "CREATION" << std::endl;
    std::cout << Vector::count << std::endl;

    Vector vec1;
    Vector vec2(2);
    Vector vec3(3, 10.0f);

    vec1.printVector();
    vec2.printVector();
    vec3.printVector();

    std::cout << "\nSET, GET" << std::endl;
    printVectorCount();

    vec2.set(1, 100.0f);
    std::cout << "Vec3 : " << vec3.get(1) << std::endl;

    std::cout << "Vec2 : ";
    vec2.printVector();

    std::cout << "\nADD, SUB, MUL" << std::endl;
    printVectorCount();

    vec3.Add(vec2);
    vec2.Sub(vec3);

    vec3.Mul(2.0f);

    std::cout << "Vec2 : ";
    vec2.printVector();

    std::cout << "Vec3 : ";
    vec3.printVector();

    std::cout << "\nLARGER, SMALLER" << std::endl;
    printVectorCount();

    bool larger = vec2.LargerThan(vec3);
    bool lesser = vec2.LessThan(vec3);

    std::cout << "Vec2 Larger Than Vec3: " << larger << std::endl;
    std::cout << "Vec2 Less than Vec3 : " << lesser << std::endl;

    vec3.~Vector();
    vec2.~Vector();
    vec1.~Vector();

    printVectorCount();
}

void printVectorCount()
{
    std::cout << "\nAmount of Vectors : " << Vector::count << std::endl;
}
