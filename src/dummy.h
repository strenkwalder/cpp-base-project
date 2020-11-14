#ifndef DUMMY_H
#define DUMMY_H


class Dummy
{
public:
    Dummy();
    ~Dummy() = default;

    Dummy(const Dummy &other) = default;
    Dummy(Dummy &&other) = default;
    Dummy &operator=(const Dummy &other) = default;
    Dummy &operator=(Dummy &&other) = default;

    bool hasData();

    int *&data();
private:
    int *m_data;
};

#endif // DUMMY_H
