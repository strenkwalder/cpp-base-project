#ifndef DUMMY_H
#define DUMMY_H


class Dummy
{
public:
    Dummy();
    ~Dummy() = default;

    Dummy(const Dummy &other);
    Dummy(Dummy &&other);
    Dummy &operator=(const Dummy &other);
    Dummy &operator=(Dummy &&other);

    int *data();
private:
    int *m_data;
};

#endif // DUMMY_H
