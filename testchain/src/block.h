/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     Blockchain tutorial project 'TestChain' with C++
 * @file      block.h
 * @reference https://davenash.com/2017/10/build-a-blockchain-with-c/
 */

#ifndef TESTCHAIN_SRC_BLOCK_H_
#define TESTCHAIN_SRC_BLOCK_H_

#include <cstdint>
#include <iostream>
#include <string>

using std::string;

class Block {
 public:
  Block(uint32_t index, const string& data);

  string get_hash();
  string get_prev_hash();

  void MineBlock(uint32_t difficulty);

 private:
  uint32_t index_;
  int64_t nonce_;
  string data_;
  string hash_;
  string prev_hash_;
  time_t time_;

  string CalculateHash() const;
};

#endif  // TESTCHAIN_SRC_BLOCK_H_
