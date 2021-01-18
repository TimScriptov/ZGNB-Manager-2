/**
 * Copyright 2011 Ryszard Wi?niewski <brut.alll@gmail.com>
 * Modified Copyright 2015 com.zenggeHai <2801045898@qq.com>
 * <p>
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * <p>
 * http://www.apache.org/licenses/LICENSE-2.0
 * <p>
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.zengge.nbmanager.arsceditor.ResDecoder;

import com.zengge.nbmanager.arsceditor.ResDecoder.data.ResResource;

import java.io.IOException;


/**
 * @author Ryszard Wi?niewski <brut.alll@gmail.com>
 * @author com.zenggeHai
 */
public interface GetResValues {
    public void getResValues(ARSCCallBack back, ResResource res) throws IOException;
}
