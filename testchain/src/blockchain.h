/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     Blockchain toy project 'TestChain' with C++
 * @file      blockchain.h
 * @reference https://davenash.com/2017/10/build-a-blockchain-with-c/
 */

#ifndef TESTCHAIN_SRC_BLOCKCHAIN_H_
#define TESTCHAIN_SRC_BLOCKCHAIN_H_

#include <cstdint>
#include <vector>

#include "block.h"

using std::vector;

class Blockchain {
 public:
  Blockchain();

  void AddBlock(Block new_block);

 private:
  uint32_t difficulty_;
  vector<Block> chain_;

  Block GetLastBlock() const;
};

#endif  // TESTCHAIN_SRC_BLOCKCHAIN_H_
