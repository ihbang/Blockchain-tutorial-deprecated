/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     Blockchain toy project 'TestChain' with C++
 * @file      block.cc
 * @reference https://davenash.com/2017/10/build-a-blockchain-with-c/
 */

// Self header
#include "block.h"

#include <sstream>

#include "sha256/sha256.h"

using std::string;

Block::Block(uint32_t index, const string& data)
    : index_(index), nonce_(-1), data_(data), time_(time(nullptr)) {}

string Block::get_hash() { return hash_; }
string Block::get_prev_hash() { return prev_hash_; }

void Block::set_prev_hash(std::string prev_hash) { prev_hash_ = prev_hash; }

void Block::MineBlock(uint32_t difficulty) {
  string str(difficulty, '0');

  do {
    nonce_++;
    hash_ = CalculateHash();
  } while (hash_.substr(0, difficulty) != str);

  std::cout << "Block mined: " << hash_ << std::endl;
}

inline string Block::CalculateHash() const {
  std::stringstream ss;
  ss << index_ << time_ << data_ << nonce_ << prev_hash_;

  return sha256(ss.str());
}
