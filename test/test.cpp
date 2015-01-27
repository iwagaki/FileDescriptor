#include <gtest/gtest.h>
#include "../FilePointer.h"

TEST(FileReadPointer, FileAccess) { 
    {
        FileReadPointer reader("../LICENSE");
        ASSERT_EQ(0, fseeko(reader, 0, SEEK_SET));
    }
}
 
// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
