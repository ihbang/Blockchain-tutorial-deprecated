/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     Blockchain toy project 'TestChain' with C++
 * @file      blockchain.cc
 * @reference https://davenash.com/2017/10/build-a-blockchain-with-c/
 */

#include "blockchain.h"

using std::vector;

Blockchain::Blockchain() : difficulty_(6) {
  chain_.emplace_back(Block(0, "Genesis Block"));
}

void Blockchain::AddBlock(Block new_block) {
  new_block.set_prev_hash(GetLastBlock().get_hash());
  new_block.MineBlock(difficulty_);
  chain_.push_back(new_block);
}

Block Blockchain::GetLastBlock() const { return chain_.back(); }
