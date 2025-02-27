/* Copyright 2022 The DeepRec Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
======================================================================*/

#ifndef TENSORFLOW_CORE_FRAMEWORK_EMBEDDING_BATCH_
#define TENSORFLOW_CORE_FRAMEWORK_EMBEDDING_BATCH_

#if GOOGLE_CUDA
namespace tensorflow {

template<class V>
__global__ void BatchCopy(V** batch, V* val_base, int value_len,
    int limit, V** default_value, bool* init_flags);

template<class V>
__global__ void BatchUnpack(V** dev_value_address, V* memcpy_buffer_gpu,
    int value_len, int limit);

template<class V>
__global__ void SparseApplyAdagradGPU(V** a, V** v, V* g, float lr,
    int embedding_dim, long long int limit,
    bool* init_flags, V* default_value);

template<class V>
__global__ void CopyEmbedding(V** batch, V** batch_data_space,
    int total_dims, int limit);

}  // namespace tensorflow

#endif  // GOOGLE_CUDA

#endif  // TENSORFLOW_CORE_FRAMEWORK_EMBEDDING_BATCH_
