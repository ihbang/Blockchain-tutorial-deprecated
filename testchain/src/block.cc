/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     Blockchain toy project 'TestChain' with C++
 * @file      block.cc
 * @reference https://davenash.com/2017/10/build-a-blockchain-with-c/
 */

// Self header
#include "block.h"

#include <iomanip>
#include <sstream>

#include "openssl/sha.h"

using std::string;

/**
 * convert openssl sha256 function to generate c++ style string
 * reference: https://cypsw.tistory.com/70
 */
string sha256(const string str) {
  unsigned char digest[SHA256_DIGEST_LENGTH];
  std::stringstream ss;

  SHA256((const unsigned char*)str.c_str(), str.length(), digest);

  for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
    ss << std::hex << std::setw(2) << std::setfill('0')
       << static_cast<int>(digest[i]);
  }
  return ss.str();
}

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
