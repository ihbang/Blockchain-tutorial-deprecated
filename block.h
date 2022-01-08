// Copyright 2022 Inhyeok Bang
// Blockchain tutorial with C++
// Reference - https://davenash.com/2017/10/build-a-blockchain-with-c/

#ifndef BLOCK_H_
#define BLOCK_H_

#include <cstdint>
#include <iostream>
#include <string>

using std::string;

class Block {
 public:
  Block(uint32_t index, const string &data);
  string GetHash();
  void MineBlock(uint32_t difficulty);

 private:
  uint32_t index_;
  int64_t nonce_;
  string data_;
  string hash_;
  string prev_hash_;
  time_t time_;
};

#endif  // BLOCK_H_
