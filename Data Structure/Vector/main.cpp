#include "Vector.h"
#include <iostream>

struct Entity {
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Entity() {}
    Entity(float scalar) : x(scalar), y(scalar), z(scalar) {}
    Entity(float x, float y, float z) : x(x), y(y), z(z) {}

    Entity(const Entity& other) : x(other.x), y(other.y), z(other.z) {
        std::cout << "Copy constructor\n";
    }

    Entity(Entity&& other) noexcept : x(other.x), y(other.y), z(other.z) {
        std::cout << "Move constructor\n";
    }

    Entity& operator=(const Entity& other) {
        std::cout << "Copy assignment\n";
        x = other.x; y = other.y; z = other.z;
        return *this;
    }

    Entity& operator=(Entity&& other) noexcept {
        std::cout << "Move assignment\n";
        x = other.x; y = other.y; z = other.z;
        return *this;
    }

    ~Entity() {
        std::cout << "Destroyed\n";
    }
};

template <typename T>
void PrintData(Vector<T>& value) {
    for (size_t i = 0; i < value.Size(); ++i)
        std::cout << value[i].x << " " << value[i].y << " " << value[i].z << "\n";
    std::cout << "-------------------------\n";
}

int main() {
    Vector<Entity> vec;

    vec.EmplaceBack();
    vec.EmplaceBack(1.0f);
    vec.EmplaceBack(2.0f, 3.0f, 4.0f);
    vec.EmplaceBack(5.0f, 6.0f, 7.0f);
    vec.EmplaceBack(8.0f, 9.0f, 10.0f);
    PrintData(vec);

    vec.PopBack();
    vec.PopBack();
    PrintData(vec);

    vec.clear();
    PrintData(vec);

    return 0;
}
