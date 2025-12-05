string postToInfix(string exp) {
//         int i = 0;
//         stack<string> st;
//         int n = exp.size();
//         while(i<n){
//             if(isalnum(exp[i])) {
//                 st.push(exp[i]);
//             }
//             else {
//                 string t1 = st.top();
//                 st.pop();
//                 string t2 = st.top();
//                 st.pop();
//                 string t = "(" +t2 +exp[i] + t1 +")";
//                 st.push(t);
                
//             }
//             i++;
//         }
//         return st.top();
//     }