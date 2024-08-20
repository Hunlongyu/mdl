import{_ as O,M as j}from"./addTask-BqkaiPJb.js";import{c as E,a as C,b as g,d as r,e as F,u as W,f as $,g as K,h as L,i as h,F as M,j as U,_ as q,r as x,k as H,l as d,m as e,w as t,o as G,n,p as J,N as Q,q as X,B as f,s as Y,t as Z}from"./index-DU6IfN-l.js";import{u as ee,_ as te,a as oe,b as ne,c as se}from"./use-message-1m9-TyaD.js";import{A as ie,M as ae,P as le,a as re,D as de,C as ce}from"./PlayOne-6v26MF2Z.js";const ue=E("divider",`
 position: relative;
 display: flex;
 width: 100%;
 box-sizing: border-box;
 font-size: 16px;
 color: var(--n-text-color);
 transition:
 color .3s var(--n-bezier),
 background-color .3s var(--n-bezier);
`,[C("vertical",`
 margin-top: 24px;
 margin-bottom: 24px;
 `,[C("no-title",`
 display: flex;
 align-items: center;
 `)]),g("title",`
 display: flex;
 align-items: center;
 margin-left: 12px;
 margin-right: 12px;
 white-space: nowrap;
 font-weight: var(--n-font-weight);
 `),r("title-position-left",[g("line",[r("left",{width:"28px"})])]),r("title-position-right",[g("line",[r("right",{width:"28px"})])]),r("dashed",[g("line",`
 background-color: #0000;
 height: 0px;
 width: 100%;
 border-style: dashed;
 border-width: 1px 0 0;
 `)]),r("vertical",`
 display: inline-block;
 height: 1em;
 margin: 0 8px;
 vertical-align: middle;
 width: 1px;
 `),g("line",`
 border: none;
 transition: background-color .3s var(--n-bezier), border-color .3s var(--n-bezier);
 height: 1px;
 width: 100%;
 margin: 0;
 `),C("dashed",[g("line",{backgroundColor:"var(--n-color)"})]),r("dashed",[g("line",{borderColor:"var(--n-color)"})]),r("vertical",{backgroundColor:"var(--n-color)"})]),_e=Object.assign(Object.assign({},$.props),{titlePlacement:{type:String,default:"center"},dashed:Boolean,vertical:Boolean}),pe=F({name:"Divider",props:_e,setup(s){const{mergedClsPrefixRef:l,inlineThemeDisabled:c}=W(s),u=$("Divider","-divider",ue,U,s,l),i=K(()=>{const{common:{cubicBezierEaseInOut:o},self:{color:v,textColor:k,fontWeight:b}}=u.value;return{"--n-bezier":o,"--n-color":v,"--n-text-color":k,"--n-font-weight":b}}),a=c?L("divider",void 0,i,s):void 0;return{mergedClsPrefix:l,cssVars:c?void 0:i,themeClass:a==null?void 0:a.themeClass,onRender:a==null?void 0:a.onRender}},render(){var s;const{$slots:l,titlePlacement:c,vertical:u,dashed:i,cssVars:a,mergedClsPrefix:o}=this;return(s=this.onRender)===null||s===void 0||s.call(this),h("div",{role:"separator",class:[`${o}-divider`,this.themeClass,{[`${o}-divider--vertical`]:u,[`${o}-divider--no-title`]:!l.default,[`${o}-divider--dashed`]:i,[`${o}-divider--title-position-${c}`]:l.default&&c}],style:a},u?null:h("div",{class:`${o}-divider__line ${o}-divider__line--left`}),!u&&l.default?h(M,null,h("div",{class:`${o}-divider__title`},this.$slots),h("div",{class:`${o}-divider__line ${o}-divider__line--right`})):null)}}),m=s=>(Y("data-v-3b0285b7"),s=s(),Z(),s),ge={class:"download"},fe=m(()=>d("span",null,"添加下载任务",-1)),me=m(()=>d("span",null,"批量添加下载任务",-1)),he=m(()=>d("span",null,"开始下载",-1)),ve=m(()=>d("span",null,"停止下载",-1)),ke=m(()=>d("span",null,"删除任务",-1)),be=m(()=>d("span",null,"清空已完成任务",-1)),we=m(()=>d("span",null,"视频合并",-1)),Ce={__name:"download",setup(s){const l=ee(),c=x([{key:"uuid1",name:"Wonderwall",process:"20%",speed:"1Mbps",status:"下载中",remainder:"12:04:18"},{key:"uuid2",name:"Don't Look Back in Anger",process:"60%",speed:"1Mbps",status:"下载中",remainder:"4:48"},{key:"uuid3",name:"Champagne Supernova",process:"100%",speed:"0Mbps",status:"合并中",remainder:"0:00"},{key:"uuid4",name:"I love you",process:"100%",speed:"0Mbps",status:"已完成",remainder:"0:00"}]),u=[{type:"selection"},{title:"名称",key:"name",align:"left",minWidth:200,ellipsis:{tooltip:!0}},{title:"进度",key:"process",width:100,align:"center"},{title:"速度",key:"speed",width:100,align:"center"},{title:"状态",key:"status",width:100,align:"center"},{title:"剩余时间",key:"remainder",width:100,align:"center"}],i=x([]);function a(y){i.value=y}const o=x(!1);function v(){o.value=!0}function k(){}function b(){console.log("confirm"),l.success("添加下载任务成功")}function T(){console.log(i.value),l.info("开始下载任务")}function B(){console.log(i.value)}function P(){console.log(i.value)}function V(){}function R(){console.log(i.value)}return(y,z)=>{const _=Q,p=X,I=pe,D=te,N=se,S=oe,A=ne;return G(),H(M,null,[d("div",ge,[e(D,{bordered:"",class:"download-header"},{default:t(()=>[e(p,{trigger:"hover"},{trigger:t(()=>[e(n(f),{circle:"",onClick:v},{default:t(()=>[e(_,{size:"18"},{default:t(()=>[e(n(ie))]),_:1})]),_:1})]),default:t(()=>[fe]),_:1}),e(p,{trigger:"hover"},{trigger:t(()=>[e(n(f),{circle:"",onClick:k},{default:t(()=>[e(_,{size:"18"},{default:t(()=>[e(n(ae))]),_:1})]),_:1})]),default:t(()=>[me]),_:1}),e(p,{trigger:"hover"},{trigger:t(()=>[e(n(f),{circle:"",onClick:T},{default:t(()=>[e(_,{size:"18"},{default:t(()=>[e(n(le))]),_:1})]),_:1})]),default:t(()=>[he]),_:1}),e(p,{trigger:"hover"},{trigger:t(()=>[e(n(f),{circle:"",onClick:B},{default:t(()=>[e(_,{size:"18"},{default:t(()=>[e(n(re))]),_:1})]),_:1})]),default:t(()=>[ve]),_:1}),e(p,{trigger:"hover"},{trigger:t(()=>[e(n(f),{circle:"",onClick:P},{default:t(()=>[e(_,{size:"18"},{default:t(()=>[e(n(de))]),_:1})]),_:1})]),default:t(()=>[ke]),_:1}),e(p,{trigger:"hover"},{trigger:t(()=>[e(n(f),{circle:"",onClick:V},{default:t(()=>[e(_,{size:"18"},{default:t(()=>[e(n(ce))]),_:1})]),_:1})]),default:t(()=>[be]),_:1}),e(I,{vertical:""}),e(p,{trigger:"hover"},{trigger:t(()=>[e(n(f),{circle:"",onClick:R},{default:t(()=>[e(_,{size:"18"},{default:t(()=>[e(n(j))]),_:1})]),_:1})]),default:t(()=>[we]),_:1})]),_:1}),e(S,{class:"download-content","native-scrollbar":!1},{default:t(()=>[e(N,{striped:"",columns:u,data:c.value,pagination:!1,bordered:!1,"row-key":w=>w.key,"onUpdate:checkedRowKeys":a},null,8,["data","row-key"])]),_:1}),e(A,{bordered:"",class:"download-footer"},{default:t(()=>[J(" log ")]),_:1})]),e(O,{modelValue:o.value,"onUpdate:modelValue":z[0]||(z[0]=w=>o.value=w),onAddTaskConfirm:b},null,8,["modelValue"])],64)}}},Me=q(Ce,[["__scopeId","data-v-3b0285b7"]]);export{Me as default};
