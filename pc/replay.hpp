#pragma once

#include <pc/mem_map.hpp>
#include <pc/error.hpp>
#include <oracle/oracle.h>
#include <zlib.h>

namespace pc
{

  // replay pyth aggregate prices from capture file
  class replay : public error
  {
  public:

    replay();
    ~replay();

    // capture file
    void set_file( const std::string& cap_file );
    std::string get_file() const;

    // (re) initialize
    bool init();

    // time of price capture
    int64_t get_time() const;

    // on-chain price capture
    pc_price_t *get_update() const;

    // get next price capture
    bool get_next();

  private:

    int64_t     ts_;
    pc_price_t *up_;
    char       *buf_;
    size_t      pos_;
    size_t      len_;
    gzFile      zfd_;
    std::string file_;
  };

  inline int64_t replay::get_time() const
  {
    return ts_;
  }

  inline pc_price_t *replay::get_update() const
  {
    return up_;
  }

}
