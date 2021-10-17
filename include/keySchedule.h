#pragma once

class keySchedule
{
private:
    unsigned char** m_key;
public:
    keySchedule(unsigned char key[]);
    ~keySchedule();

    unsigned char* popKey();
};
