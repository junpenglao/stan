#ifndef __STAN__COMMON__WARMUP_HPP__
#define __STAN__COMMON__WARMUP_HPP__

#include <stan/mcmc/base_mcmc.hpp>
#include <stan/io/mcmc_writer.hpp>
#include <stan/common/run_markov_chain.hpp>

namespace stan {
  namespace common {

    template <class Model, class RNG>
    void warmup(stan::mcmc::base_mcmc* sampler,
                int num_warmup,
                int num_samples,
                int num_thin,
                int refresh,
                bool save,
                stan::io::mcmc_writer<Model>& writer,
                stan::mcmc::sample& init_s,
                Model& model,
                RNG& base_rng) {
      run_markov_chain<Model, RNG>(sampler, num_warmup, 0, num_warmup + num_samples, num_thin,
                                   refresh, save, true,
                                   writer,
                                   init_s, model, base_rng);
    }
  }
}

#endif
