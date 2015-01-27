#ifndef FILE_POINTER_H_
#define FILE_POINTER_H_

#include <cstdio>
#include "check.h"


class FilePointer
{
public:
    FilePointer(const char* filename, const char* attr = "wb") : m_fp(0)
    {
        CHECK(filename != 0);

        m_fp = fopen(filename, attr);
//        CHECK(m_fp != 0);
    }

    virtual ~FilePointer()
    {
        if (m_fp)
        {
            if (fclose(m_fp) != 0)
                assert(0);

            m_fp = 0;
        }
    }

    operator FILE*() const
    {
        return fp();
    }

    FILE* fp() const
    {
//        CHECK(m_fp != 0);
        return m_fp;
    }

private:
    FILE* m_fp;
};


class FileReadPointer : public FilePointer
{
public:
    FileReadPointer(const char* filename) : FilePointer(filename, "rb") {}
};


class FileWritePointer : public FilePointer
{
public:
    FileWritePointer(const char* filename) : FilePointer(filename, "wb") {}
};


#endif // FILE_POINTER_H_
