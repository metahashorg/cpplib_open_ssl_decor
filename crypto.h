#ifndef CRYPTO_H
#define CRYPTO_H

#include <vector>
#include <string>


typedef struct {
  std::vector<unsigned char> private_key_buf;
  std::vector<unsigned char> public_key_buf;
  std::vector<unsigned char> mh_address_buf;
  int nonce = 0;

} CRYPTO_wallet;


void CRYPTO_generate_wallet(
  CRYPTO_wallet& wallet, 
  const std::string& password = "");

void CRYPTO_generate_wallet(
  std::string& private_key, 
  std::string& public_key, 
  std::string& mh_address, 
  const std::string& password = "");

void CRYPTO_init_wallet(
  CRYPTO_wallet& wallet,
  const std::string& private_key, 
  const std::string& public_key, 
  const std::string& mh_address);

void CRYPTO_sign_text(
  std::vector<unsigned char>& sign, 
  const std::string& private_key, 
  const std::string& text, 
  const std::string& password = "");

void CRYPTO_sign_data(
  std::vector<unsigned char>& sign, 
  const std::string& private_key, 
  const std::vector<unsigned char>& data, 
  const std::string& password = "");

bool CRYPTO_check_sign_text(
  const std::vector<unsigned char>& sign, 
  const std::string& public_key, 
  const std::string& text);

bool CRYPTO_check_sign_data(
  const std::vector<unsigned char>& sign, 
  const std::string& public_key, 
  const std::vector<unsigned char>& data);

#endif
