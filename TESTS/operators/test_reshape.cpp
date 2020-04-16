#include <cstring>
#include <iostream>

#include "arenaAllocator.hpp"
#include "context.hpp"
#include "Reshape.hpp"
#include "RamTensor.hpp"
#include "RomTensor.hpp"

#include "gtest/gtest.h"

#include "constants_reshape.hpp"

using namespace uTensor;
 
TEST(Reshape, reshape_test) {
  localCircularArenaAllocator<1024> meta_allocator;
  localCircularArenaAllocator<15*2*sizeof(float), uint32_t> ram_allocator;
  Context::get_default_context()->set_metadata_allocator(&meta_allocator);
  Context::get_default_context()->set_ram_data_allocator(&ram_allocator);
  Tensor input_tensor = new RomTensor({ 3,5 }, flt, random_input_arr);
  Tensor output_tensor = new RamTensor({ 5,3,1 }, flt);
  ReshapeOperator<float> op;
  op
    .set_inputs({ { ReshapeOperator<float>::input, input_tensor } })
    .set_outputs({ { ReshapeOperator<float>::output, output_tensor } })
    .eval();
  for (int i = 0; i < 15; ++i) {
    EXPECT_NEAR((float) output_tensor(i), ref_output_arr[i], 0.0001);
  }
  TensorShape target_shape(5, 3, 1);
  TensorShape output_shape = output_tensor->get_shape();
  EXPECT_TRUE(target_shape == output_shape);

}