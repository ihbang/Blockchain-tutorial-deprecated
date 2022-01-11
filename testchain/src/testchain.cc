/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     Blockchain toy project 'TestChain' with C++
 * @file      main.cc
 * @reference https://davenash.com/2017/10/build-a-blockchain-with-c/
 */

#include "blockchain.h"

int main() {
  Blockchain chain = Blockchain();

  std::cout << "Mining block 1..." << std::endl;
  chain.AddBlock(Block(1, "Block 1 Data"));

  std::cout << "Mining block 2..." << std::endl;
  chain.AddBlock(Block(2, "Block 2 Data"));

  std::cout << "Mining block 3..." << std::endl;
  chain.AddBlock(Block(3, "Block 3 Data"));

  return 0;
}
