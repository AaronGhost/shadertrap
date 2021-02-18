// Copyright 2020 The ShaderTrap Project Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LIBSHADERTRAP_COMMAND_BIND_UNIFORM_BUFFER_H
#define LIBSHADERTRAP_COMMAND_BIND_UNIFORM_BUFFER_H

#include <cstddef>
#include <memory>
#include <string>

#include "libshadertrap/command.h"
#include "libshadertrap/token.h"

namespace shadertrap {

class CommandBindUniformBuffer : public Command {
 public:
  CommandBindUniformBuffer(std::unique_ptr<Token> start_token,
                           std::unique_ptr<Token> buffer_identifier,
                           size_t binding);

  bool Accept(CommandVisitor* visitor) override;

  const std::string& GetBufferIdentifier() const {
    return buffer_identifier_->GetText();
  }

  const Token* GetBufferIdentifierToken() const {
    return buffer_identifier_.get();
  }

  size_t GetBinding() const { return binding_; }

 private:
  std::unique_ptr<Token> buffer_identifier_;
  size_t binding_;
};

}  // namespace shadertrap

#endif  // LIBSHADERTRAP_COMMAND_BIND_UNIFORM_BUFFER_H
