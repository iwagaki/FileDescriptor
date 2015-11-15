#include <gtest/gtest.h>
#include "../FilePointer.h"

TEST(FileReadPointer, CannotOpenInvalidFileName) {
    FileReadPointer reader("data/hogehoge");
    ASSERT_EQ(NULL, static_cast<FILE*>(reader));
}

TEST(FileReadPointer, CannotOpenInvalidFileName_fp) {
    FileReadPointer reader("data/hogehoge");
    ASSERT_EQ(NULL, reader.fp());
}

TEST(FileReadPointer, FileAccess) {
    {
        FileReadPointer reader("../LICENSE");
        ASSERT_EQ(0, fseeko(reader, 0, SEEK_SET));
    }
}

TEST(FileWritePointer, CannotOpenReadOnlyFile) {
    FileWritePointer writer("data/ro_data");
    ASSERT_EQ(NULL, static_cast<FILE*>(writer));
}

TEST(FileWritePointer, CannotOpenReadOnlyFile_fp) {
    FileWritePointer writer("data/ro_data");
    ASSERT_EQ(NULL, writer.fp());
}


// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
