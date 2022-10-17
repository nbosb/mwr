/******************************************************************************
 *                                                                            *
 * Copyright 2018 Jan Henrik Weinstock                                        *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License");            *
 * you may not use this file except in compliance with the License.           *
 * You may obtain a copy of the License at                                    *
 *                                                                            *
 *     http://www.apache.org/licenses/LICENSE-2.0                             *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 *                                                                            *
 ******************************************************************************/

#include "mwr/core/report.h"
#include "mwr/core/utils.h"

namespace mwr {

report::report(const string& msg, const char* file, size_t line):
    std::exception(),
    m_message(msg),
    m_file(file),
    m_line(line),
    m_backtrace(mwr::backtrace(max_backtrace_length, 2)) {
    // nothing to do
}

report::~report() throw() {
    // nothing to do
}

const char* report::what() const throw() {
    return m_message.c_str();
}

} // namespace mwr
