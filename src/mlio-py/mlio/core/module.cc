/*
 * Copyright 2019-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not use this file except in compliance with the License. A copy of
 * the License is located at
 *
 *      http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF
 * ANY KIND, either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 */

#include "module.h"

namespace pymlio {

PYBIND11_MODULE(_core, m)
{
    m.attr("__name__") = "mlio";

    mlio::initialize();

    m.def(
        "supports_s3",
        &mlio::supports_s3,
        "Return a boolean value indicating whether the library was built with Amazon S3 support.");

    m.def(
        "supports_image_reader",
        &mlio::supports_image_reader,
        "Return a boolean value indicating whether the library was built with image reader support.");

    register_exceptions(m);
    register_logging(m);
    register_s3_client(m);
    register_memory_slice(m);
    register_device_array(m);
    register_tensors(m);
    register_integ(m);
    register_streams(m);
    register_data_stores(m);
    register_record_readers(m);
    register_schema(m);
    register_example(m);
    register_data_readers(m);
}

}  // namespace pymlio
