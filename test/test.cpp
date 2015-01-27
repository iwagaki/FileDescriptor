#include <gtest/gtest.h>
#include "../FileDescriptor.h"

TEST(FileReadDescriptor, FileAccess) { 
    {
        FileReadDescriptor reader("../LICENSE");
        ASSERT_EQ(0, fseeko(reader, 0, SEEK_SET));
    }
}
 
// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
