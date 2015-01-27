#ifndef FILE_DESCRIPTOR_H_
#define FILE_DESCRIPTOR_H_

#include <cstdio>
#include "check.h"


class FileDescriptor
{
public:
    FileDescriptor(const char* filename, const char* attr = "wb") : m_fp(0)
    {
        CHECK(filename != 0);

        m_fp = fopen(filename, attr);
//        CHECK(m_fp != 0);
    }

    virtual ~FileDescriptor()
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


class FileReadDescriptor : public FileDescriptor
{
public:
    FileReadDescriptor(const char* filename) : FileDescriptor(filename, "rb") {}
};


class FileWriteDescriptor : public FileDescriptor
{
public:
    FileWriteDescriptor(const char* filename) : FileDescriptor(filename, "wb") {}
};


#endif // FILE_DESCRIPTOR_H_
