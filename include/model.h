/* -*- Header -*-
 *
 * The Model Enumeration
 *
 * Author: Fuqi Jia <jiafq@ios.ac.cn>
 *
 * Copyright (C) 2025 Fuqi Jia
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef _MODEL_H
#define _MODEL_H

#include "dag.h"

namespace SMTLIBParser{
    class Model{
        public:
            Model();
            Model(const Model &other);
            ~Model();

            /**
             * @brief Add a variable to the model
             * 
             * @param node Variable to add
             */
            void add(const std::shared_ptr<DAGNode> &node, const std::shared_ptr<DAGNode> &value);

            /**
             * @brief Add a variable to the model
             * 
             * @param name Variable name
             */
            void add(const std::string &name, const std::shared_ptr<DAGNode> &value);

            /**
             * @brief Add a variable to the model
             * 
             * @param node Variable to add
             */
            void addVar(const std::shared_ptr<DAGNode> &node);

            /**
             * @brief Get a variable from the model
             * 
             * @param node Variable to get
             * @return Variable
             */
            std::shared_ptr<DAGNode> get(const std::shared_ptr<DAGNode> &node);

            /**
             * @brief Get a variable from the model
             * 
             * @param name Variable name
             * @return Variable
             */
            std::shared_ptr<DAGNode> get(const std::string &name);

            /**
             * @brief Check if the model is full
             * 
             * @return True if the model is full, false otherwise
             */
            bool isFull() const;

            /**
             * @brief Check if the model is empty
             * 
             * @return True if the model is empty, false otherwise
             */
            bool isEmpty() const;

            /**
             * @brief Clear the model
             */
            void clear();

            /**
             * @brief Get the size of the model
             * 
             * @return The size of the model
             */
            size_t size() const;

            /**
             * @brief Get the variables of the model
             * 
             * @return The variables of the model
             */
            std::vector<std::shared_ptr<DAGNode>> getVars() const;

            /**
             * @brief Get the values of the model
             * 
             * @return The values of the model
             */
            std::vector<std::shared_ptr<DAGNode>> getValues() const;

            /**
             * @brief Get the pairs of the model
             * 
             * @return The pairs of the model
             */
            std::vector<std::pair<std::string, std::shared_ptr<DAGNode>>> getPairs() const;

            /**
             * @brief Get the string representation of the model
             * 
             * @return The string representation of the model
             */
            std::string toString();
        private:
            std::unordered_map<std::string, size_t> model_name_index;
            std::vector<std::shared_ptr<DAGNode>> model_vars;
            std::vector<std::shared_ptr<DAGNode>> model_values;
    };

    // smart pointer
    typedef std::shared_ptr<Model> ModelPtr;
    ModelPtr newModel();
}

#endif

